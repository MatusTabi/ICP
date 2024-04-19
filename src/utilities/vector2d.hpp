#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
#include <QPoint>

struct Vector2D {
    double x_;
    double y_;

    Vector2D();
    Vector2D(double x, double y);
    Vector2D(const QPoint &point);

    const Vector2D operator*(double scalar) const;
    const Vector2D operator*(int scalar) const;
    const Vector2D &operator*=(double scalar);
    const Vector2D &operator*=(int scalar);
    const Vector2D operator+(int scalar) const;
    const Vector2D operator+(const Vector2D &vector2d) const;
    const Vector2D &operator+=(const Vector2D &vector2d);
    const Vector2D operator-(const Vector2D &vector2d) const;
    const Vector2D normalize();
    const double length();
    const double dot(const Vector2D &other) const;
    const double cross_product(const Vector2D &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &vector2d);
};

#endif
