#ifndef WALL_HPP
#define WALL_HPP

#include "../utilities/vector2d.hpp"
#include "entity.hpp"

#include <QColor>

enum Edge { None, Left, Right, Top, Bottom };

class Wall {
  public:
    Wall(double x, double y);
    Wall(double x, double y, double width, double height);
    Wall(Vector2D w_position);
    Wall(Vector2D w_position, Vector2D w_size);
    ~Wall() = default;

    const Vector2D &position();
    const Vector2D &size();
    const Qt::GlobalColor &color();

    bool contains(const Vector2D &point);
    void start_moving(const Vector2D &point);
    void start_resizing(const Vector2D &point, const Edge &edge);
    void stop_moving();
    void stop_resizing();
    Edge is_near_edge(const Vector2D &point) const;

    void relocate(const Vector2D &point);
    void resize(const Vector2D &point);

    bool &is_resizing();

  private:
    const Vector2D calculate_relocate_offset(const Vector2D &point);
    const Vector2D calculate_resizing_offset(const Vector2D &point);
    void update_relocate_position(const Vector2D &point);
    void update_resize_position(const Vector2D &point);

    Vector2D position_;
    Vector2D size_;
    Vector2D offset;
    Qt::GlobalColor color_ = Qt::black;
    bool moving_ = false;
    bool resizing_ = false;
    Edge resizing_edge_;
};

#endif
