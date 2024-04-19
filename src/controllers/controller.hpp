#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../models/robot.hpp"
#include "../models/wall.hpp"
#include "../models/entity.hpp"
#include <vector>

class Controller {
  public:
    static Controller *get_instance();
    void add_robot(Robot *new_robot);
    void add_wall(Wall *new_wall);
    void add_robot_vector(std::vector<Robot *> new_robot_vector);
    void add_wall_vector(std::vector<Wall *> new_wall_vector);

    void move_robots();
    void toggle_simulation_state();
    bool &is_simulation_running();
    void reset_color();

    std::vector<Robot *> const get_robots();
    std::vector<Wall *> const get_walls();

  private:
    bool detect_collision(Robot *robot);
    bool robot_collision(Robot *robot_1, Robot *robot_2);
    void detect_robot_collision();

    std::vector<Robot *> robot_vector;
    std::vector<Wall *> wall_vector;
    static Controller *instance;

    bool simulation_runs{false};
};

#endif
