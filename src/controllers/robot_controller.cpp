#include "robot_controller.h"
#include <iostream>

RobotController::RobotController() {}

bool RobotController::detect_collision() {
    for (Robot *robot : robot_vector) {

        QPoint r_position = robot->get_position();
        Direction r_dir = robot->get_direction();
        int r_coll_length = robot->get_collision_distance();
        std::vector<Wall *> coll_walls = walls_ifo_robot(r_position, r_dir);

        for (Wall *wall : coll_walls) {

            QPoint w_position = wall->get_position();
            QPoint w_size = wall->get_position();

            switch(r_dir) {
                case Direction::RIGHT:
                    if (r_position.x() + r_coll_length >= w_position.x()) {
                        return true;
                    }
                    break;
                case Direction::DOWN:
                    if (r_position.y() + r_coll_length >= w_position.y()) {
                        return true;
                    }
                    break;
                case Direction::LEFT:
                    if (r_position.x() - r_coll_length <= w_position.x() + w_size.x()) {
                        return true;
                    }
                    break;
                case Direction::UP:
                    if (r_position.y() - r_coll_length <= w_position.y() + w_size.y()) {
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

        QPoint w_position = wall->get_position();
        QPoint w_size = wall->get_size();

        switch(r_dir) {
            case Direction::RIGHT:
            case Direction::LEFT:
                if (w_position.y() <= r_position.y() && r_position.y() <= w_position.y() + w_size.y()) {
                    walls.push_back(wall);
                }
                break;
            case Direction::UP:
            case Direction::DOWN:
                if (w_position.x() <= r_position.x() && r_position.x() <= w_position.x() + w_size.x()) {
                    walls.push_back(wall);
                }
                break;
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

