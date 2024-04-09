#ifndef ROBOT_CONTROLLER_HPP
#define ROBOT_CONTROLLER_HPP

#include "../models/robot.hpp"
#include "../models/wall.hpp"
#include "../models/entity.hpp"
#include <vector>

class RobotController {
  public:
    static RobotController *get_instance();
    void add_robot(Robot *new_robot);
    void add_wall(Wall *new_wall);
    void add_robot_vector(std::vector<Robot *> new_robot_vector);
    void add_wall_vector(std::vector<Wall *> new_wall_vector);

    void move_robots();
    void change_collision_distance(int r_collision_distance);
    void change_properties(int r_collision_distance);

    std::vector<Robot *> const get_robots();
    std::vector<Wall *> const get_walls();

  private:
    bool overlaps_diag_static(Robot *robot, Wall *wall);
    void detect_collision(Robot *robot);
    // std::vector<Wall *> walls_ifo_robot(QPointF r_position, int r_dir);

    std::vector<Robot *> robot_vector;
    std::vector<Wall *> wall_vector;
    static RobotController *instance;
};

#endif
