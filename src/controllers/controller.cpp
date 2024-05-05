#include "controller.hpp"
#include <chrono>
#include <cmath>
#include <iostream>

using namespace std::chrono;

Controller *Controller::instance = nullptr;

Controller *Controller::get_instance() {
    if (!instance) {
        instance = new Controller();
    }
    return instance;
}

Controller::~Controller() {
    if (saver) {
        delete saver;
    }
}

bool Controller::detect_collision(RobotBase *robot) {
    Vector2D potential_position{robot->get_position() + robot->velocity()};
    const double robot_width = robot->get_width();
    const Vector2D velocity = robot->velocity();
    const int collision_distance = robot->collision_distance();

    for (Wall *wall : wall_vector) {
        const Vector2D wall_position = wall->position();
        const Vector2D wall_size = wall->size();
        Vector2D nearest_point;

        const double effective_robot_width = -robot_width + collision_distance;
        const double x1 = wall_position.x_ - collision_distance;
        const double x2 =
            wall_position.x_ + wall_size.x_ + effective_robot_width;
        const double y1 = wall_position.y_ - collision_distance;
        const double y2 =
            wall_position.y_ + wall_size.y_ + effective_robot_width;

        nearest_point.x_ = std::max(x1, std::min(potential_position.x_, x2));
        nearest_point.y_ = std::max(y1, std::min(potential_position.y_, y2));

        Vector2D distance = potential_position - nearest_point;
        double overlaps = robot_width - distance.length();
        if (overlaps > 0) {
            if (ManualRobot *manual_robot =
                    dynamic_cast<ManualRobot *>(robot)) {
                manual_robot->change_state(ManualRobotState::IDLE);
                return true;
            }
            robot->rotation_on();
            return true;
        }
    }
    robot->move();
    return false;
}

bool Controller::robot_collision(RobotBase *robot_1, RobotBase *robot_2) {
    Vector2D distance = robot_1->get_position() - robot_2->get_position();
    double radius_sum = robot_1->get_width() / 2.0 + robot_2->get_width() / 2.0;

    // Calculate the relative velocity
    Vector2D relative_velocity = robot_1->velocity() - robot_2->velocity();

    // Check if the dot product of the distance vector and relative velocity is
    // negative
    if (distance.dot(relative_velocity) >= 0) {
        return false; // Robots are moving away from each other or parallel, no
                      // collision
    }

    // Check if the length of the distance vector is less than the sum of their
    // radii
    return distance.length() < radius_sum + robot_1->collision_distance();
}

void Controller::add_robot(RobotBase *new_robot) {
    if (ManualRobot *manual_robot = dynamic_cast<ManualRobot *>(new_robot)) {
        if (has_manual_robot) {
            return;
        }
        has_manual_robot = true;
    }
    robot_vector.push_back(new_robot);
}

void Controller::add_wall(Wall *new_wall) { wall_vector.push_back(new_wall); }

void Controller::add_robot_vector(std::vector<RobotBase *> new_robot_vector) {
    robot_vector.insert(std::end(robot_vector), std::begin(new_robot_vector),
                        std::end(new_robot_vector));
}

void Controller::add_wall_vector(std::vector<Wall *> new_wall_vector) {
    wall_vector.insert(std::end(wall_vector), std::begin(new_wall_vector),
                       std::end(new_wall_vector));
}

void Controller::set_saver() {
    if (!saver) {
        saver = new Saver();
    }
}

void Controller::set_loader() {
    if (!loader) {
        loader = new Loader();
    }
}

void Controller::save_simulation() {
    set_saver();
    saver->save_simulation(robot_vector, wall_vector);
}

void Controller::load_simulation() {
    set_loader();
    std::vector<RobotBase *> new_robot_vector;
    std::vector<Wall *> new_wall_vector;
    loader->load_simulation(new_robot_vector, new_wall_vector);
    add_robot_vector(new_robot_vector);
    add_wall_vector(new_wall_vector);
}

void Controller::move_robots() {
    for (size_t i = 0; i < robot_vector.size(); ++i) {
        const Vector2D old_position = robot_vector[i]->get_position();
        RobotBase *robot = robot_vector[i];
        if (robot->is_rotating()) {
            robot->rotate();
        } else {
            bool collision = false;
            for (size_t j = 0; j < robot_vector.size(); ++j) {
                const Vector2D robot2_old_position =
                    robot_vector[j]->get_position();
                if (i == j) {
                    continue;
                }
                if (robot_collision(robot, robot_vector[j])) {
                    robot->set_position(old_position);
                    robot_vector[j]->set_position(robot2_old_position);
                    if (ManualRobot *manual_robot =
                            dynamic_cast<ManualRobot *>(robot)) {
                        manual_robot->change_state(ManualRobotState::IDLE);
                    }
                    else {
                        robot->rotation_on();
                    }
                    collision = true;
                    break;
                }
            }
            if (!collision && !detect_collision(robot)) {
                robot->colorize(RobotBase::DefaultColor);
            } else {
                robot->colorize(RobotBase::CollisionColor);
            }
        }
    }
}

bool Controller::select_robot(const Vector2D &click_position) {
    for (RobotBase *robot : robot_vector) {
        if (robot->contains(click_position)) {
            reset_color();
            selected_robot_ = robot;
            selected_robot_->colorize(RobotBase::SelectedColor);
            robot->start_moving(click_position);
            return true;
        }
    }
    return false;
}

bool Controller::select_wall(const Vector2D &click_position) {
    for (Wall *wall : wall_vector) {
        const Edge edge = wall->is_near_edge(click_position);
        if (edge != Edge::None) {
            reset_color();
            selected_wall = wall;
            selected_wall->colorize(Wall::SelectedColor);
            wall->start_resizing(click_position, edge);
            return true;
        } else if (wall->contains(click_position)) {
            reset_color();
            selected_wall = wall;
            wall->colorize(Wall::SelectedColor);
            selected_wall->start_moving(click_position);
            return true;
        }
    }
    return false;
}

void Controller::reset_robots() {
    reset_color();
    selected_robot_ = nullptr;
}

void Controller::rotate_robot_staticly(bool clockwise) {
    if (selected_robot_) {
        selected_robot_->rotate_staticly(clockwise);
    }
}

bool Controller::can_move_selected_robot(const Vector2D &new_position) {
    if (selected_robot_ && selected_robot_->is_moving()) {
        selected_robot_->relocate(new_position);
        return true;
    }
    return false;
}

bool Controller::can_move_selected_wall(const Vector2D &new_position) {
    if (selected_wall) {
        if (selected_wall->is_resizing()) {
            selected_wall->resize(new_position);
        } else {
            selected_wall->relocate(new_position);
        }
        return true;
    }
    return false;
}

const Qt::CursorShape
Controller::get_cursor_shape(const Vector2D &click_position) {
    for (Wall *wall : wall_vector) {
        const Edge edge = wall->is_near_edge(click_position);
        if (edge == Edge::Left || edge == Edge::Right) {
            return Qt::SizeHorCursor;
        }
        if (edge == Edge::Top || edge == Edge::Bottom) {
            return Qt::SizeVerCursor;
        }
    }
    return Qt::ArrowCursor;
}

void Controller::deselect_entities() {
    if (selected_robot_) {
        selected_robot_->stop_moving();
    }
    if (selected_wall) {
        selected_wall->stop_moving();
        selected_wall->stop_resizing();
        selected_wall = nullptr;
    }
}

void Controller::deselect_robot() {
    if (selected_robot_) {
        selected_robot_ = nullptr;
    }
}

void Controller::toggle_simulation_state() {
    simulation_runs = !simulation_runs;
}

bool &Controller::is_simulation_running() { return simulation_runs; }

void Controller::reset_color() {
    for (RobotBase *robot : robot_vector) {
        robot->colorize(RobotBase::DefaultColor);
    }
    for (Wall *wall : wall_vector) {
        wall->colorize(Wall::DefaultColor);
    }
}

ManualRobot *Controller::manual_robot() {
    for (RobotBase *robot : robot_vector) {
        if (ManualRobot *manual_robot = dynamic_cast<ManualRobot *>(robot)) {
            return manual_robot;
        }
    }
    return nullptr;
}

std::vector<RobotBase *> const Controller::get_robots() { return robot_vector; }

std::vector<Wall *> const Controller::get_walls() { return wall_vector; }

RobotBase *Controller::selected_robot() { return selected_robot_; }
