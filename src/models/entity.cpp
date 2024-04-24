#include "entity.hpp"

#include <cmath>

Entity::Entity(double x, double y) : position{x, y} {}

Entity::Entity(Vector2D r_position) : position{r_position} {}

Entity::Entity(double x, double y, double width, double height)
    : position{x, y}, width{width}, height{height} {}

Entity::Entity(Vector2D r_position, double width, double height)
    : position{r_position}, width{width}, height{height} {}

Entity::Entity(Vector2D r_position, Vector2D r_velocity)
    : position{r_position}, velocity_{r_velocity} {}

Entity::Entity(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle)
    : position{r_position}, velocity_{r_velocity}, rotation_angle_{
                                                       r_rotation_angle} {}

Entity::~Entity() {}

void Entity::rotation_on() { rotate_flag_ = true; }

void Entity::rotation_off() { rotate_flag_ = false; }

bool &Entity::is_rotating() { return rotate_flag_; }

void Entity::rotate() {
    if (current_rotation < rotation_angle_) {
        const double remaining_angle =
            std::min(angular_speed, rotation_angle_ - current_rotation);
        const double radian =
            remaining_angle * M_PI / 180.0; // convert to radians
        Vector2D new_velocity{
            velocity_.x_ * cos(radian) - velocity_.y_ * sin(radian),
            velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
        velocity_ = new_velocity;
        current_rotation += remaining_angle;
    } else {
        rotation_off();
        current_rotation = 0;
    }
}

bool Entity::contains(const Vector2D &point) {
    const Vector2D middle_point = get_middle_point();
    return (std::pow(point.x_ - middle_point.x_, 2) +
            std::pow(point.y_ - middle_point.y_, 2)) < std::pow(width, 2);
}

void Entity::start_moving(const Vector2D &point) {
    moving_ = true;
    offset = calculate_moving_offset(point);
}

void Entity::stop_moving() { moving_ = false; }

bool &Entity::is_moving() { return moving_; }

void Entity::rotate_staticly(const bool clockwise) {
    const double radian = angular_speed * M_PI / 180.0;

    const double cos_angle = cos(radian);
    const double sin_angle = sin(radian);

    const double sign = clockwise ? 1.0 : -1.0;

    Vector2D new_velocity{
        velocity_.x_ * cos_angle - sign * velocity_.y_ * sin_angle,
        sign * velocity_.x_ * sin_angle + velocity_.y_ * cos_angle};

    velocity_ = new_velocity;
}

void Entity::set_velocity(Vector2D r_velocity) { velocity_ = r_velocity; }

void Entity::set_velocity(double x, double y) { velocity_ = Vector2D{x, y}; }

void Entity::set_position(Vector2D r_position) { position = r_position; }

void Entity::colorize(Qt::GlobalColor r_color) { color_ = r_color; }

const Vector2D &Entity::get_position() { return position; }

const Vector2D Entity::get_size() { return Vector2D{width, height}; }

const Vector2D &Entity::velocity() { return velocity_; }

const double &Entity::get_width() { return width; }

const double &Entity::get_height() { return height; }

const Qt::GlobalColor &Entity::color() { return color_; }

const int &Entity::collision_distance() { return collision_distance_; }

const int &Entity::rotation_angle() { return rotation_angle_; }

const Vector2D Entity::calculate_moving_offset(const Vector2D &point) {
    return point - position;
}

void Entity::relocate(const Vector2D &point) {
    if (moving_) {
        update_move_position(point);
    }
}

void Entity::set_angle(int angle) { rotation_angle_ = angle; }

void Entity::update_move_position(const Vector2D &point) {
    position = point - offset;
}
