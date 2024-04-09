#include "robot_controller.hpp"
#include <cmath>
#include <iostream>

RobotController *RobotController::instance = nullptr;

RobotController *RobotController::get_instance() {
    if (!instance) {
        instance = new RobotController();
    }
    return instance;
}

void RobotController::detect_collision(Robot *robot) {
    Vector2D potential_position{robot->get_position() + robot->velocity()};
    for (Wall *wall : wall_vector) {
        Vector2D nearest_point;
        const double robot_width = robot->get_width();
        const Vector2D velocity = robot->velocity();

        nearest_point.x_ =
            std::max(wall->get_position().x_,
                     std::min(potential_position.x_,
                              wall->get_position().x_ + wall->get_size().x_ - robot_width));
        nearest_point.y_ =
            std::max(wall->get_position().y_,
                     std::min(potential_position.y_,
                              wall->get_position().y_ + wall->get_size().y_ - robot_width));

        Vector2D distance = potential_position - nearest_point;
        double overlaps = robot->get_width() - distance.length();
        if (overlaps > 0) {
            potential_position =
                potential_position + distance.normalize() * overlaps;
            robot->rotation_on();
            return;
        }
    }
    robot->set_position(potential_position);
}

void RobotController::add_robot(Robot *new_robot) {
    robot_vector.push_back(new_robot);
}

void RobotController::add_wall(Wall *new_wall) {
    wall_vector.push_back(new_wall);
}

void RobotController::add_robot_vector(std::vector<Robot *> new_robot_vector) {
    robot_vector.insert(std::end(robot_vector), std::begin(new_robot_vector),
                        std::end(new_robot_vector));
}

void RobotController::add_wall_vector(std::vector<Wall *> new_wall_vector) {
    wall_vector.insert(std::end(wall_vector), std::begin(new_wall_vector),
                       std::end(new_wall_vector));
}

void RobotController::change_properties(int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        // robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::change_collision_distance(int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        // robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::move_robots() {
    for (Robot *robot : robot_vector) {
        if (robot->is_rotating()) {
            robot->colorize(Qt::red);
            robot->rotate();
        } else {
            robot->colorize(Qt::white);
            detect_collision(robot);
        }
    }
}

std::vector<Robot *> const RobotController::get_robots() {
    return robot_vector;
}

std::vector<Wall *> const RobotController::get_walls() { return wall_vector; }
