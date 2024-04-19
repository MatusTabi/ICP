#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../utilities/vector2d.hpp"
#include <QColor>

class Entity {

  public:
    static const Qt::GlobalColor CollisionColor = Qt::red;
    static const Qt::GlobalColor DefaultColor = Qt::black;
    static const Qt::GlobalColor SelectedColor = Qt::blue;

    Entity(double x, double y);
    Entity(Vector2D r_position);
    Entity(double x, double y, double width, double height);
    Entity(Vector2D r_position, double width, double height);
    Entity(Vector2D r_position, Vector2D r_velocity);
    Entity(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle);

    virtual ~Entity();

    virtual void update() = 0;
    virtual void move() = 0;

    virtual const Vector2D get_middle_point() = 0;

    void adjust_position(const int kTileSize);
    void rotation_on();
    void rotation_off();
    bool &is_rotating();
    void rotate();
    bool contains(const Vector2D &point);
    void start_moving(const Vector2D &point);
    void stop_moving();
    bool &is_moving();
    void rotate_staticly(const bool clockwise);

    void set_velocity(Vector2D r_velocity);
    void set_velocity(double x, double y);
    void set_position(Vector2D r_position);
    void colorize(Qt::GlobalColor r_color);
    void relocate(const Vector2D &point);
    void set_angle(int angle);

    const Vector2D &get_position();
    const Vector2D get_size();
    const Vector2D &velocity();
    const double &get_width();
    const double &get_height();
    const Qt::GlobalColor &color();
    const int &collision_distance();
    const int &rotation_angle();

  protected:
    bool rotate_flag_ = false;
    int rotation_angle_ = 50;
    int collision_distance_ = 20;
    int angular_speed = 1;
    int current_rotation = 0;
    Vector2D position;
    Vector2D velocity_;
    double width = 30;
    double height;
    Qt::GlobalColor color_ = Entity::DefaultColor;
  
  private:
    const Vector2D calculate_moving_offset(const Vector2D &point);
    void update_move_position(const Vector2D &point);

    Vector2D offset;
    bool moving_ = false;
};

#endif
