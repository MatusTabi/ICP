#include "robot_controller.h"
#include <iostream>

RobotController::RobotController() {}

bool RobotController::detect_collision() {
    for (Robot *robot : robot_vector) {

        const QPoint r_position{robot->get_position()};
        const Direction r_dir{robot->get_direction()};
        const int r_collision_distance{robot->get_collision_distance()};
        const std::vector<Wall *> collision_walls{walls_ifo_robot(r_position, r_dir)};

        for (Wall *wall : collision_walls) {

            const QPoint w_position{wall->get_position()};
            const QPoint w_size{wall->get_size()};

            const int r_right_bound{r_position.x() + r_collision_distance};
            const int r_bottom_bound{r_position.y() + r_collision_distance};
            const int r_left_bound{r_position.x() - r_collision_distance};
            const int r_top_bound{r_position.y() - r_collision_distance};

            switch(r_dir) {
                case Direction::RIGHT:
                    if (r_right_bound >= w_position.x()) {
                        return true;
                    }
                    break;
                case Direction::DOWN:
                    if (r_bottom_bound >= w_position.y()) {
                        return true;
                    }
                    break;
                case Direction::LEFT:
                    if (r_left_bound <= w_position.x() + w_size.x()) {
                        return true;
                    }
                    break;
                case Direction::UP:
                    if (r_top_bound <= w_position.y() + w_size.y()) {
                        return true;
                    }
                    break;
            }
        }
    }
    return false;
}

std::vector<Wall *> RobotController::walls_ifo_robot(QPoint r_position, Direction r_dir) {
    std::vector<Wall *> walls;

    for (Wall *wall : wall_vector) {

        const QPoint w_position{wall->get_position()};
        const QPoint w_size{wall->get_size()};

        bool intersects{false};

        switch(r_dir) {
            case Direction::RIGHT:
            case Direction::LEFT:
                intersects = (w_position.y() <= r_position.y() && r_position.y() <= w_position.y() + w_size.y());
                break;
            case Direction::UP:
            case Direction::DOWN:
                intersects = (w_position.x() <= r_position.x() && r_position.x() <= w_position.x() + w_size.x());
                break;
        }

        if (intersects) {
            walls.push_back(wall);
        }
    }
    return walls;
}

void RobotController::add_robot(Robot *new_robot) {
    robot_vector.push_back(new_robot);
}

void RobotController::add_wall(Wall *new_wall) {
    wall_vector.push_back(new_wall);
}

void RobotController::add_robot_vector(std::vector<Robot *> new_robot_vector) {
    robot_vector.insert(std::end(robot_vector), std::begin(new_robot_vector), std::end(new_robot_vector));
}

void RobotController::add_wall_vector(std::vector<Wall *> new_wall_vector) {
    wall_vector.insert(std::end(wall_vector), std::begin(new_wall_vector), std::end(new_wall_vector));
}

std::vector<Robot *> const RobotController::get_robots() {
    return robot_vector;
}

std::vector<Wall *> const RobotController::get_walls() {
    return wall_vector;
}

void RobotController::change_properties(RobotSpeed r_speed, int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        robot->set_speed(r_speed);
        robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::change_collision_distance(int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::change_speed(RobotSpeed r_speed) {
    for (Robot *robot : robot_vector) {
        robot->set_speed(r_speed);
    }
}

void RobotController::move_robots(const bool collision) {
    if (collision) {
        for (Robot *robot : robot_vector) {
            robot->rotate();
        }
        return;
    }
    for (Robot *robot : robot_vector) {
        robot->move();
    }
}

