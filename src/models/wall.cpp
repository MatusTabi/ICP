#include "wall.hpp"
#include <iostream>

const QColor Wall::DefaultColor = QColor(255, 255, 255);
const QColor Wall::SelectedColor = QColor(173, 216, 255);
const Vector2D Wall::DefaultPosition = Vector2D{200, 200};
const Vector2D Wall::DefaultSize = Vector2D{50, 50};

Wall::Wall(double x, double y) : position_{x, y} {}

Wall::Wall(Vector2D w_position) : position_{w_position} {}

Wall::Wall(Vector2D w_position, Vector2D w_size)
    : position_{w_position}, size_{w_size} {}

Wall::Wall(Vector2D w_position, Vector2D w_size, QColor color)
    : position_{w_position}, size_{w_size}, color_{color} {}

const Vector2D &Wall::position() { return position_; }

const Vector2D &Wall::size() { return size_; }

const QColor &Wall::color() { return color_; }

bool Wall::contains(const Vector2D &point) {
    return point.x_ >= position_.x_ && point.x_ <= position_.x_ + size_.x_ &&
           point.y_ >= position_.y_ && point.y_ <= position_.y_ + size_.y_;
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

    Vector2D top_left{position_};
    Vector2D top_right{position_ + Vector2D{size_.x_, 0}};
    Vector2D bottom_left{position_ + Vector2D{0, size_.y_}};
    Vector2D bottom_right{position_ + size_};

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

void Wall::colorize(const QColor &color) { color_ = color; }

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
    return point - position_;
}

const Vector2D Wall::calculate_resizing_offset(const Vector2D &point) {
    return point - (position_ + size_);
}

void Wall::update_relocate_position(const Vector2D &point) {
    position_ = point - offset;
}

void Wall::update_resize_position(const Vector2D &point) {
    switch (resizing_edge_) {
    case Edge::Right:
        size_.x_ = point.x_ - position_.x_;
        break;
    case Edge::Bottom:
        size_.y_ = point.y_ - position_.y_;
        break;
    case Edge::Left:
        size_.x_ += position_.x_ - point.x_;
        position_.x_ = point.x_;
        break;
    case Edge::Top:
        size_.y_ += position_.y_ - point.y_;
        position_.y_ = point.y_;
        break;
    default:
        break;
    }
}

bool &Wall::is_resizing() { return resizing_; }
