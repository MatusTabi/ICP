#ifndef WALL_HPP
#define WALL_HPP

#include "../utilities/vector2d.hpp"
#include "entity.hpp"

#include <QColor>

class Wall {
  public:
    Wall(double x, double y);
    Wall(double x, double y, double width, double height);
    Wall(Vector2D w_position);
    ~Wall() = default;

    const Vector2D &get_position();
    const Vector2D &get_size();
    const Qt::GlobalColor &get_color();

  private:
    Vector2D position;
    Vector2D size;
    Qt::GlobalColor color = Qt::blue;
};

#endif
