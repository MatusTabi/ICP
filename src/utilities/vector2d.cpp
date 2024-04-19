#include "vector2d.hpp"
#include <cmath>

Vector2D::Vector2D() : x_{0}, y_{0} {}

Vector2D::Vector2D(double x, double y) : x_{x}, y_{y} {}

Vector2D::Vector2D(const QPoint &point) : x_(point.x()), y_(point.y()) {}

const Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D{x_ * scalar, y_ * scalar};
}

const Vector2D Vector2D::operator*(int scalar) const {
    return Vector2D{x_ * scalar, y_ * scalar};
}

const Vector2D &Vector2D::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

const Vector2D &Vector2D::operator*=(int scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

const Vector2D Vector2D::operator+(int scalar) const {
    return Vector2D(x_ + scalar, y_ + scalar);
}

const Vector2D Vector2D::operator+(const Vector2D &vector2d) const {
    return Vector2D(x_ + vector2d.x_, y_ + vector2d.y_);
}

const Vector2D &Vector2D::operator+=(const Vector2D &vector2d) {
    x_ += vector2d.x_;
    y_ += vector2d.y_;
    return *this;
}

const Vector2D Vector2D::operator-(const Vector2D &vector2d) const {
    return Vector2D(x_ - vector2d.x_, y_ - vector2d.y_);
}

const Vector2D Vector2D::normalize() {
    double length = this->length();
    if (length != 0) {
        return Vector2D{x_ / length, y_ / length};
    }
    return Vector2D{0, 0};
}

const double Vector2D::length() { return std::sqrt(x_ * x_ + y_ * y_); }

const double Vector2D::dot(const Vector2D &other) const {
    return x_ * other.x_ + y_ * other.y_;
}

const double Vector2D::cross_product(const Vector2D &other) const {
    return x_ * other.y_ - y_ * other.x_;
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vector2d) {
    os << "Vector2D(" << vector2d.x_ << ", " << vector2d.y_ << ")";
    return os;
}
