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

    // Robot(QPointF r_position, int r_rotation_angle);
    // Robot(QPointF r_position, int r_rotation_angle,
    //       RotationDirection r_rotation_direction);

    void update() override;
    void move() override;

    const Vector2D get_middle_point() override;

    const Vector2D compute_direction_line();

    // const int get_collision_distance();
    // const int get_rotation_angle();
    // const int get_speed();
    // const int get_target_rotation_angle();
    // const int get_angular_velocity();
    // const int has_collided();

    // void set_collision_distance(int r_coll_length);
    // void collided();
    // void can_move();
    // const bool is_rotating();

  private:
    const double speed = 1.0;
    // int collision_distance = 40;
    // int rotation_angle = 0;
    // int target_rotation_angle = 40;
    // int angular_velocity = 1;
    // bool collide = false;
    RotationDirection rotation_direction = CLOCKWISE;
};

#endif
