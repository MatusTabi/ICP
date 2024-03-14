#include "wall.h"

Wall::Wall(QPoint w_position) : position(w_position) {}

Wall::Wall(QPoint w_position, QPoint w_size) : position(w_position), size(w_size) {}

Wall::Wall(QPoint w_position, QPoint w_size, Qt::GlobalColor w_color)
    : position(w_position), size(w_size), color(w_color) {}

QPoint const Wall::get_position() {
    return position;
}

QPoint const Wall::get_size() {
    return size;
}

Qt::GlobalColor const Wall::get_color() {
    return color;
}
