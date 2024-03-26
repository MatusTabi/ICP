#ifndef ROBOT_H
#define ROBOT_H

#include <QPointF>

enum RotationDirection { CLOCKWISE, ANTICLOCKWISE };

class Robot {
  public:
    Robot(double x, double y);
    Robot(QPointF r_position);
    Robot(QPointF r_position, int r_rotation_angle);
    Robot(QPointF r_position, int r_rotation_angle,
          RotationDirection r_rotation_direction);

    void move();
    void rotate();

    const QPointF get_position();
    const int get_collision_distance();
    const int get_rotation_angle();
    const int get_size();

    void set_collision_distance(int r_coll_length);
    void set_position(QPointF intermediate_position);

  private:
    QPointF position;
    const int size = 20;
    const double speed = 1.0;
    int collision_distance = 40;
    int rotation_angle = 0;
    RotationDirection rotation_direction = CLOCKWISE;
};

#endif
