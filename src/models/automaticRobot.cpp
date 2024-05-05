#include "automaticRobot.hpp"

#include <cmath>
#include <iostream>

AutomaticRobot::AutomaticRobot(double x, double y) : RobotBase{x, y} {}

AutomaticRobot::AutomaticRobot(Vector2D r_position) : RobotBase{r_position} {}

AutomaticRobot::AutomaticRobot(Vector2D r_position, Vector2D r_velocity)
    : RobotBase{r_position, r_velocity} {}

AutomaticRobot::AutomaticRobot(Vector2D r_position, Vector2D r_velocity,
                               int r_rotation_angle, QColor r_color)
    : RobotBase{r_position, r_velocity, r_rotation_angle, r_color} {}

void AutomaticRobot::move() { position_ += velocity_; }

void AutomaticRobot::rotate() {
    if (current_rotation < rotation_angle_) {
        const double remaining_angle =
            std::min(angular_speed_, rotation_angle_ - current_rotation);
        const double radian =
            remaining_angle * M_PI / 180.0; // convert to radians
        Vector2D new_velocity;
        if (rotation_direction_ == RotationDirection::CLOCKWISE) {
            new_velocity = Vector2D{
                velocity_.x_ * cos(radian) - velocity_.y_ * sin(radian),
                velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
        } else {
            new_velocity = Vector2D{
                velocity_.x_ * cos(radian) + velocity_.y_ * sin(radian),
                -velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
        }
        velocity_ = new_velocity;
        current_rotation += remaining_angle;
    } else {
        rotation_off();
        current_rotation = 0;
    }
}

const QString AutomaticRobot::type() { return "AutomaticRobot"; }
