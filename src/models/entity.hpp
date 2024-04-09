#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../utilities/vector2d.hpp"
#include <QColor>

class Entity {

  public:
    Entity(double x, double y);
    Entity(Vector2D r_position);
    Entity(double x, double y, double width, double height);
    Entity(Vector2D r_position, double width, double height);
    Entity(Vector2D r_position, Vector2D r_velocity);

    virtual ~Entity();

    virtual void update() = 0;
    virtual void move() = 0;

    virtual const Vector2D get_middle_point() = 0;

    void adjust_position(const int kTileSize);
    void rotation_on();
    void rotation_off();
    bool &is_rotating();
    void rotate();

    void set_velocity(Vector2D r_velocity);
    void set_velocity(double x, double y);
    void set_position(Vector2D r_position);
    void colorize(Qt::GlobalColor r_color);

    const Vector2D &get_position();
    const Vector2D get_size();
    const Vector2D &velocity();
    const double &get_width();
    const double &get_height();
    const Qt::GlobalColor &color();
    const int &get_collision_distance();

  protected:
    bool rotate_flag_ = false;
    int rotation_angle_ = 40;
    int collision_distance = 40;
    int angular_speed = 1;
    int current_rotation = 0;
    Vector2D position;
    Vector2D velocity_;
    double width = 30;
    double height;
    Qt::GlobalColor color_ = Qt::white;
};

#endif
