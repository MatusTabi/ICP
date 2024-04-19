#include "wall.hpp"
#include <iostream>

Wall::Wall(double x, double y) : position{x, y} {}

Wall::Wall(Vector2D w_position) : position{w_position} {}

Wall::Wall(double x, double y, double width, double height)
    : position{x, y}, size{width, height} {}

const Vector2D &Wall::get_position() { return position; }

const Vector2D &Wall::get_size() { return size; }

const Qt::GlobalColor &Wall::get_color() { return color; }

bool Wall::contains(const Vector2D &point) {
    return point.x_ >= position.x_ && point.x_ <= position.x_ + size.x_ &&
           point.y_ >= position.y_ && point.y_ <= position.y_ + size.y_;
}

void Wall::start_moving(const Vector2D &point) {
    moving_ = true;
    offset = calculate_relocate_offset(point);
}

void Wall::start_resizing(const Vector2D &point, const Edge &edge) {
    resizing_ = true;
    resizing_edge_ = edge;
    offset = calculate_resizing_offset(point);
}

void Wall::stop_moving() { moving_ = false; }

void Wall::stop_resizing() { resizing_ = false; }

Edge Wall::is_near_edge(const Vector2D &point) const {
    const double KEdgeTreshold = 5.0;

    Vector2D top_left{position};
    Vector2D top_right{position + Vector2D{size.x_, 0}};
    Vector2D bottom_left{position + Vector2D{0, size.y_}};
    Vector2D bottom_right{position + size};

    if (std::abs(point.x_ - top_left.x_) < KEdgeTreshold) {
        if (point.y_ > top_left.y_ && point.y_ < bottom_left.y_) {
            return Edge::Left;
        }
    } else if (std::abs(point.x_ - top_right.x_) < KEdgeTreshold) {
        if (point.y_ > top_right.y_ && point.y_ < bottom_right.y_) {
            return Edge::Right;
        }
    }

    if (std::abs(point.y_ - top_left.y_) < KEdgeTreshold) {
        if (point.x_ > top_left.x_ && point.x_ < top_right.x_) {
            return Edge::Top;
        }
    } else if (std::abs(point.y_ - bottom_left.y_) < KEdgeTreshold) {
        if (point.x_ > bottom_left.x_ && point.x_ < bottom_right.x_) {
            return Edge::Bottom;
        }
    }
    return Edge::None;
}

void Wall::relocate(const Vector2D &point) {
    if (moving_) {
        update_relocate_position(point);
    }
}

void Wall::resize(const Vector2D &point) {
    if (resizing_) {
        update_resize_position(point);
    }
}

const Vector2D Wall::calculate_relocate_offset(const Vector2D &point) {
    return point - position;
}

const Vector2D Wall::calculate_resizing_offset(const Vector2D &point) {
    return point - (position + size);
}

void Wall::update_relocate_position(const Vector2D &point) {
    position = point - offset;
}

void Wall::update_resize_position(const Vector2D &point) {
    switch (resizing_edge_) {
    case Edge::Right:
        size.x_ = point.x_ - position.x_;
        break;
    case Edge::Bottom:
        size.y_ = point.y_ - position.y_;
        break;
    case Edge::Left:
        size.x_ += position.x_ - point.x_;
        position.x_ = point.x_;
        break;
    case Edge::Top:
        size.y_ += position.y_ - point.y_;
        position.y_ = point.y_;
        break;
    default:
        break;
    }
}

bool &Wall::is_resizing() { return resizing_; }
