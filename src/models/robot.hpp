#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "entity.hpp"

enum RotationDirection { CLOCKWISE, ANTICLOCKWISE };

class Robot : public Entity {
  public:
    Robot(double x, double y);
    Robot(Vector2D r_position);
    Robot(Vector2D r_position, Vector2D r_velocity);
    Robot(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle);

    void update() override;
    void move() override;

    const Vector2D get_middle_point() override;
    const Vector2D compute_direction_line();

  private:
    const double speed = 1.0;
    RotationDirection rotation_direction = CLOCKWISE;
};

#endif
