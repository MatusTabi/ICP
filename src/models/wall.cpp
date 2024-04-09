#include "wall.hpp"
#include <iostream>

Wall::Wall(double x, double y) : position{x, y} {}

Wall::Wall(Vector2D w_position) : position{w_position} {}

Wall::Wall(double x, double y, double width, double height)
    : position{x, y}, size{width, height} {}

const Vector2D &Wall::get_position() { return position; }

const Vector2D &Wall::get_size() { return size; }

const Qt::GlobalColor &Wall::get_color() { return color; }
