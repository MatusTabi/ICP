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

void Entity::adjust_position(const int kTileSize) { position *= kTileSize; }

void Entity::rotation_on() { rotate_flag_ = true; }

void Entity::rotation_off() { rotate_flag_ = false; }

bool &Entity::is_rotating() { return rotate_flag_; }

void Entity::rotate() {
    if (current_rotation < rotation_angle_) {
        double radian = angular_speed * M_PI / 180.0; // convert to radians
        Vector2D new_velocity{
            velocity_.x_ * cos(radian) - velocity_.y_ * sin(radian),
            velocity_.x_ * sin(radian) + velocity_.y_ * cos(radian)};
        velocity_ = new_velocity;
        current_rotation += angular_speed;
    } else {
        rotation_off();
        current_rotation = 0;
    }
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
