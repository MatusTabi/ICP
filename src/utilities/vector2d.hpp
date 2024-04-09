#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

struct Vector2D {
    double x_;
    double y_;

    Vector2D();
    Vector2D(double x, double y);

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

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &vector2d);
};

#endif
