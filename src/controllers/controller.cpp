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

// TODO Implementing BoundingBox for robot.
// TODO const BoundingBox robot_bb = robot->get_bounding_box();
// TODO if (!wall->intersects(robot_bb))
// TODO     continue;
bool Controller::detect_collision(Robot *robot) {
    Vector2D potential_position{robot->get_position() + robot->velocity()};
    const double robot_width = robot->get_width();
    const Vector2D velocity = robot->velocity();
    const int collision_distance = robot->collision_distance();

    for (Wall *wall : wall_vector) {
        const Vector2D wall_position = wall->get_position();
        const Vector2D wall_size = wall->get_size();
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
            potential_position =
                potential_position + distance.normalize() * overlaps;
            robot->rotation_on();
            return true;
        }
    }
    robot->set_position(potential_position);
    return false;
}

void Controller::add_robot(Robot *new_robot) {
    robot_vector.push_back(new_robot);
}

void Controller::add_wall(Wall *new_wall) { wall_vector.push_back(new_wall); }

void Controller::add_robot_vector(std::vector<Robot *> new_robot_vector) {
    robot_vector.insert(std::end(robot_vector), std::begin(new_robot_vector),
                        std::end(new_robot_vector));
}

void Controller::add_wall_vector(std::vector<Wall *> new_wall_vector) {
    wall_vector.insert(std::end(wall_vector), std::begin(new_wall_vector),
                       std::end(new_wall_vector));
}

void Controller::move_robots() {
    for (Robot *robot : robot_vector) {
        if (robot->is_rotating()) {
            robot->rotate();
            robot->colorize(Entity::CollisionColor);
        } else {
            if (!detect_collision(robot)) {
                robot->colorize(Entity::DefaultColor);
            }
        }
    }
}

void Controller::toggle_simulation_state() {
    simulation_runs = !simulation_runs;
}

bool &Controller::is_simulation_running() { return simulation_runs; }

std::vector<Robot *> const Controller::get_robots() { return robot_vector; }

std::vector<Wall *> const Controller::get_walls() { return wall_vector; }
