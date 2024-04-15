#include "robot.hpp"

#include <cmath>
#include <iostream>

Robot::Robot(double x, double y) : Entity{x, y} {}

Robot::Robot(Vector2D r_position) : Entity{r_position} {}

Robot::Robot(Vector2D r_position, Vector2D r_velocity)
    : Entity{r_position, r_velocity} {}

Robot::Robot(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle)
    : Entity{r_position, r_velocity, r_rotation_angle} {}

void Robot::update() {}

void Robot::move() { position += velocity_; }

const Vector2D Robot::get_middle_point() {
    return Vector2D{position.x_ + width / 2, position.y_ + width / 2};
}

const Vector2D Robot::compute_direction_line() {
    return get_middle_point() + velocity_.normalize() * (width / 2);
}
