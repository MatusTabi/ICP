#include "robot.h"

#include <cmath>
#include <iostream>

Robot::Robot(double x, double y) : position{x, y} {}

Robot::Robot(QPointF r_position) : position{r_position} {}

Robot::Robot(QPointF r_position, int r_rotation_angle)
    : position{r_position}, rotation_angle{r_rotation_angle} {}

Robot::Robot(QPointF r_position, int r_rotation_angle,
             RotationDirection r_rotation_direction)
    : position{r_position}, rotation_angle{r_rotation_angle},
      rotation_direction{r_rotation_direction} {}

void Robot::move() {
    double radian = rotation_angle * M_PI / 180.0; // radians
    position.setX(position.x() + speed * cos(radian));
    position.setY(position.y() - speed * sin(radian));
}

void Robot::rotate() {
    if (rotation_direction == RotationDirection::CLOCKWISE) {
        // direction = (direction + 90) % 360;
    } else {
        // direction = (direction + 270) % 360;
    }
}

const QPointF Robot::get_position() { return position; }

const int Robot::get_collision_distance() { return collision_distance; }

const int Robot::get_rotation_angle() { return rotation_angle; }

const int Robot::get_size() { return size; }

void Robot::set_collision_distance(int r_coll_length) {
    collision_distance = r_coll_length;
}

void Robot::set_position(QPointF intermediate_position) {
    position = intermediate_position;
}
