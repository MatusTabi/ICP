#include "robot_controller.hpp"
#include <iostream>

RobotController *RobotController::instance = nullptr;

RobotController *RobotController::get_instance() {
    if (!instance) {
        instance = new RobotController();
    }
    return instance;
}

bool RobotController::detect_collision(Robot *robot) {

    const QPointF r_position{robot->get_position()};
    const int r_rotation_angle{robot->get_rotation_angle()};
    const int r_collision_distance{robot->get_collision_distance()};
    const std::vector<Wall *> collision_walls{
        walls_ifo_robot(r_position, r_rotation_angle)};

    for (Wall *wall : collision_walls) {

        const QPoint w_position{wall->get_position()};
        const QPoint w_size{wall->get_size()};

        const double r_right_bound{r_position.x() + r_collision_distance};
        const double r_bottom_bound{r_position.y() + r_collision_distance};
        const double r_left_bound{r_position.x() - r_collision_distance};
        const double r_top_bound{r_position.y() - r_collision_distance};
        bool collide{false};

        switch (r_rotation_angle) {
        case 0:
            if (r_right_bound >= w_position.x()) {
                collide = true;
            }
            break;
        case 270:
            if (r_bottom_bound >= w_position.y()) {
                collide = true;
            }
            break;
        case 180:
            if (r_left_bound <= w_position.x() + w_size.x()) {
                collide = true;
            }
            break;
        case 90:
            if (r_top_bound <= w_position.y() + w_size.y()) {
                collide = true;
            }
            break;
        }
        if (collide) {
            return true;
        }
    }
    return false;
}

std::vector<Wall *> RobotController::walls_ifo_robot(QPointF r_position,
                                                     int r_rotation_angle) {
    std::vector<Wall *> walls;

    for (Wall *wall : wall_vector) {
        const QPoint w_position{wall->get_position()};
        const QPoint w_size{wall->get_size()};
        bool intersects{false};

        switch (r_rotation_angle) {
        case 0:
        case 180:
            intersects = (w_position.y() <= r_position.y() &&
                          r_position.y() <= w_position.y() + w_size.y());
            break;
        case 90:
        case 270:
            intersects = (w_position.x() <= r_position.x() &&
                          r_position.x() <= w_position.x() + w_size.x());
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
    robot_vector.insert(std::end(robot_vector), std::begin(new_robot_vector),
                        std::end(new_robot_vector));
}

void RobotController::add_wall_vector(std::vector<Wall *> new_wall_vector) {
    wall_vector.insert(std::end(wall_vector), std::begin(new_wall_vector),
                       std::end(new_wall_vector));
}

void RobotController::change_properties(int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::change_collision_distance(int r_collision_distance) {
    for (Robot *robot : robot_vector) {
        robot->set_collision_distance(r_collision_distance);
    }
}

void RobotController::move_robots() {
    for (Robot *robot : robot_vector) {
        if (detect_collision(robot)) {
            robot->rotate();
        } else {
            robot->move();
        }
    }
}

std::vector<Robot *> const RobotController::get_robots() {
    return robot_vector;
}

std::vector<Wall *> const RobotController::get_walls() { return wall_vector; }
