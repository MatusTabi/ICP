#include "manualRobot.hpp"

ManualRobot::ManualRobot(double x, double y) : RobotBase{x, y} {}

ManualRobot::ManualRobot(Vector2D r_position) : RobotBase{r_position} {}

ManualRobot::ManualRobot(Vector2D r_position, Vector2D r_velocity)
    : RobotBase{r_position, r_velocity} {}

ManualRobot::ManualRobot(Vector2D r_position, Vector2D r_velocity,
                         int r_rotation_angle, QColor r_color)
    : RobotBase{r_position, r_velocity, r_rotation_angle, r_color} {}

void ManualRobot::move() {
    if (state_ == MOVING) {
        position_ += velocity_;
    }
}

void ManualRobot::rotate() {
    const double radian = angular_speed_ * M_PI / 180.0; // convert to radians
    Vector2D new_velocity;

    if (state_ == ROTATE_LEFT) {
        new_velocity =
            Vector2D{velocity_.x_ * cos(radian) + velocity_.y_ * sin(radian),
                     -velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
    } else if (state_ == ROTATE_RIGHT) {
        new_velocity =
            Vector2D{velocity_.x_ * cos(radian) - velocity_.y_ * sin(radian),
                     velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
    }
    velocity_ = new_velocity;
}

const QString ManualRobot::type() { return "ManualRobot"; }

const Vector2D ManualRobot::second_circle_point() {
    const double x = position_.x_ + second_width / 2;
    const double y = position_.y_ + second_width / 2;
    return Vector2D{x, y};
}

void ManualRobot::change_state(const ManualRobotState new_state) {
    state_ = new_state;
}

const ManualRobotState ManualRobot::state() { return state_; }
