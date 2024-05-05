/**
 * @file controller.hpp
 *
 * @brief The file contains the declaration of the Controller class.
 *
 * The class represents the controller of the application.
 *
 * The controller is responsible for managing the robots and walls in the
 * simulation. It also provides the functionality to save and load the
 * simulation.
 *
 * The controller is a singleton.
 *
 * @author Matus Tabi
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../models/automaticRobot.hpp"
#include "../models/manualRobot.hpp"
#include "../models/wall.hpp"
#include "../services/loader.hpp"
#include "../services/saver.hpp"
#include <vector>

class Controller {
  public:
    /**
     * @brief Returns the instance of the Controller class.
     *
     * @return The instance of the Controller class.
     */
    static Controller *get_instance();

    /**
     * @brief Destructor of the Controller class.
     */
    ~Controller();

    /**
     * @brief Adds a robot to the simulation.
     *
     * @param new_robot The robot that will be added to the simulation.
     */
    void add_robot(RobotBase *new_robot);

    /**
     * @brief Adds a wall to the simulation.
     *
     * @param new_wall The wall that will be added to the simulation.
     */
    void add_wall(Wall *new_wall);

    /**
     * @brief Adds a vector of robots to the simulation.
     *
     * @param new_robot_vector The vector of robots that will be added to the
     * simulation.
     */
    void add_robot_vector(std::vector<RobotBase *> new_robot_vector);

    /**
     * @brief Adds a vector of walls to the simulation.
     *
     * @param new_wall_vector The vector of walls that will be added to the
     * simulation.
     */
    void add_wall_vector(std::vector<Wall *> new_wall_vector);

    /**
     * @brief Saves the simulation.
     */
    void save_simulation();

    /**
     * @brief Loads the simulation.
     */
    void load_simulation();

    /**
     * @brief Moves the robots in the simulation.
     */
    void move_robots();

    /**
     * @brief Toggles the simulation state.
     */
    void toggle_simulation_state();

    /**
     * @brief Returns the state of the simulation.
     *
     * @return The state of the simulation.
     */
    bool &is_simulation_running();

    /**
     * @brief Resets the color of the robots.
     */
    void reset_color();

    /**
     * @brief Selects a robot.
     *
     * @param click_position The position of the click.
     *
     * @return True if the robot was selected, false otherwise.
     */
    bool select_robot(const Vector2D &click_position);

    /**
     * @brief Selects a wall.
     *
     * @param click_position The position of the click.
     *
     * @return True if the wall was selected, false otherwise.
     */
    bool select_wall(const Vector2D &click_position);

    /**
     * @brief Resets the robots.
     */
    void reset_robots();

    /**
     * @brief Rotates the selected robot staticly.
     *
     * @param clockwise The direction of the rotation.
     */
    void rotate_robot_staticly(bool clockwise);

    /**
     * @brief Method that checks if the robot can move to the new position.
     *
     * @param new_position The new position of the robot.
     *
     * @return True if the robot can move to the new position, false otherwise.
     */
    bool can_move_selected_robot(const Vector2D &new_position);

    /**
     * @brief Method that checks if the wall can move to the new position.
     *
     * @param new_position The new position of the wall.
     *
     * @return True if the wall can move to the new position, false otherwise.
     */
    bool can_move_selected_wall(const Vector2D &new_position);

    /**
     * @brief Method that returns the cursor shape.
     *
     * @param click_position The position of the click.
     *
     * @return The cursor shape.
     */
    const Qt::CursorShape get_cursor_shape(const Vector2D &click_position);

    /**
     * @brief Deselects the entities.
     */
    void deselect_entities();

    /**
     * @brief Deselects the robot.
     */
    void deselect_robot();

    /**
     * @brief Method that returns the manual robot.
     *
     * @return The manual robot.
     */
    ManualRobot *manual_robot();

    /**
     * @brief Method that returns the robots.
     *
     * @return The robots.
     */
    std::vector<RobotBase *> const get_robots();

    /**
     * @brief Method that returns the walls.
     *
     * @return The walls.
     */
    std::vector<Wall *> const get_walls();

    /**
     * @brief Method that returns the selected robot.
     *
     * @return The selected robot.
     */
    RobotBase *selected_robot();

  private:
    /**
     * @brief Method that checks if the robot collides with the wall.
     *
     * @param robot The robot.
     *
     * @return True if the robot collides with the wall, false otherwise.
     */
    bool detect_collision(RobotBase *robot);

    /**
     * @brief Method that checks if the robot collides with the robot.
     *
     * @param robot_1 The first robot.
     * @param robot_2 The second robot.
     *
     * @return True if the robot collides with the robot, false otherwise.
     */
    bool robot_collision(RobotBase *robot_1, RobotBase *robot_2);

    /**
     * @brief Method that sets the saver.
     */
    void set_saver();

    /**
     * @brief Method that sets the loader.
     */
    void set_loader();

    /**
     * @brief Vector of robots.
     */
    std::vector<RobotBase *> robot_vector;

    /**
     * @brief Vector of walls.
     */
    std::vector<Wall *> wall_vector;

    /**
     * @brief The instance of the Controller class.
     */
    static Controller *instance;

    /**
     * @brief The saver.
     */
    Saver *saver = nullptr;

    /**
     * @brief The loader.
     */
    Loader *loader = nullptr;

    /**
     * @brief The selected robot.
     */
    RobotBase *selected_robot_ = nullptr;

    /**
     * @brief The selected wall.
     */
    Wall *selected_wall = nullptr;

    /**
     * @brief Flag that indicates if the simulation runs.
     */
    bool simulation_runs{false};

    /**
     * @brief Flag that indicates if the manual robot exists.
     */
    bool has_manual_robot{false};
};

#endif
