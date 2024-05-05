// #include "robot_base.hpp"
#include "robotBase.hpp"

#include <cmath>

const QColor RobotBase::CollisionColor = QColor(255, 0, 0);
const QColor RobotBase::DefaultColor = QColor(255, 255, 255);
const QColor RobotBase::SelectedColor = QColor(173, 216, 255);
const Vector2D RobotBase::DefaultPosition = Vector2D{300, 300};
const Vector2D RobotBase::DefaultVelocity = Vector2D{1, 0};

RobotBase::RobotBase(double x, double y) : position_{x, y} {}

RobotBase::RobotBase(Vector2D r_position) : position_{r_position} {}

RobotBase::RobotBase(Vector2D r_position, Vector2D r_velocity)
    : position_{r_position}, velocity_{r_velocity} {}

RobotBase::RobotBase(Vector2D r_position, Vector2D r_velocity,
                     int r_rotation_angle, QColor r_color)
    : position_{r_position}, velocity_{r_velocity},
      rotation_angle_{r_rotation_angle}, color_{r_color} {}

RobotBase::~RobotBase() {}

void RobotBase::rotation_on() { rotate_flag_ = true; }

void RobotBase::rotation_off() { rotate_flag_ = false; }

bool &RobotBase::is_rotating() { return rotate_flag_; }

bool RobotBase::contains(const Vector2D &point) {
    const Vector2D middle_point = get_middle_point();
    return (std::pow(point.x_ - middle_point.x_, 2) +
            std::pow(point.y_ - middle_point.y_, 2)) < std::pow(width, 2);
}

void RobotBase::start_moving(const Vector2D &point) {
    moving_ = true;
    offset = calculate_moving_offset(point);
}

void RobotBase::stop_moving() { moving_ = false; }

bool &RobotBase::is_moving() { return moving_; }

void RobotBase::rotate_staticly(const bool clockwise) {
    const double radian = angular_speed_ * M_PI / 180.0;

    const double cos_angle = cos(radian);
    const double sin_angle = sin(radian);

    const double sign = clockwise ? 1.0 : -1.0;

    Vector2D new_velocity{
        velocity_.x_ * cos_angle - sign * velocity_.y_ * sin_angle,
        sign * velocity_.x_ * sin_angle + velocity_.y_ * cos_angle};

    velocity_ = new_velocity;
}

void RobotBase::set_velocity(Vector2D r_velocity) { velocity_ = r_velocity; }

void RobotBase::set_position(Vector2D r_position) { position_ = r_position; }

void RobotBase::set_collision_distance(const int r_collision_distance) {
    collision_distance_ = r_collision_distance;
}

void RobotBase::set_angular_speed(const int r_angular_speed) {
    angular_speed_ = r_angular_speed;
}

void RobotBase::colorize(QColor r_color) { color_ = r_color; }

void RobotBase::set_rotation_direction(const RotationDirection direction) {
    rotation_direction_ = direction;
}

const RotationDirection &RobotBase::rotation_direction() {
    return rotation_direction_;
}

const int &RobotBase::angular_speed() { return angular_speed_; }

const Vector2D &RobotBase::get_position() { return position_; }

const double &RobotBase::get_size() { return width; }

const double &RobotBase::get_width() { return width; }

const Vector2D &RobotBase::velocity() { return velocity_; }

const QColor &RobotBase::color() { return color_; }

const int &RobotBase::collision_distance() { return collision_distance_; }

const int &RobotBase::rotation_angle() { return rotation_angle_; }

const Vector2D RobotBase::calculate_moving_offset(const Vector2D &point) {
    return point - position_;
}

void RobotBase::relocate(const Vector2D &point) {
    if (moving_) {
        update_move_position(point);
    }
}

void RobotBase::set_angle(int angle) { rotation_angle_ = angle; }

void RobotBase::update_move_position(const Vector2D &point) {
    position_ = point - offset;
}

const Vector2D RobotBase::compute_direction_line() {
    return get_middle_point() + velocity_.normalize() * (width / 2);
}

const Vector2D RobotBase::get_middle_point() {
    return Vector2D{position_.x_ + width / 2, position_.y_ + width / 2};
}
