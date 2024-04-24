#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../models/robot.hpp"
#include "../models/wall.hpp"
#include "../models/entity.hpp"
#include "../services/saver.hpp"
#include "../services/loader.hpp"
#include <vector>

class Controller {
  public:
    static Controller *get_instance();
    ~Controller();
    void add_robot(Robot *new_robot);
    void add_wall(Wall *new_wall);
    void add_robot_vector(std::vector<Robot *> new_robot_vector);
    void add_wall_vector(std::vector<Wall *> new_wall_vector);

    void set_saver();
    void set_loader();
    void save_simulation();
    void load_simulation();
    void move_robots();
    void toggle_simulation_state();
    bool &is_simulation_running();
    void reset_color();

    bool select_robot(const Vector2D &click_position);
    bool select_wall(const Vector2D &click_position);
    void reset_robots();
    void rotate_robot_staticly(bool clockwise);
    bool can_move_selected_robot(const Vector2D &new_position);
    bool can_move_selected_wall(const Vector2D &new_position);
    const Qt::CursorShape get_cursor_shape(const Vector2D &click_position);
    void deselect();

    std::vector<Robot *> const get_robots();
    std::vector<Wall *> const get_walls();

  private:
    bool detect_collision(Robot *robot);
    bool robot_collision(Robot *robot_1, Robot *robot_2);

    std::vector<Robot *> robot_vector;
    std::vector<Wall *> wall_vector;
    static Controller *instance;

    Saver *saver = nullptr;
    Loader *loader = nullptr;

    Robot *selected_robot = nullptr;
    Wall *selected_wall = nullptr;

    bool simulation_runs{false};
};

#endif
