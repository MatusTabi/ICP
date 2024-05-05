/**
 * @file loader.hpp
 *
 * @brief Definition of the Loader class.
 *
 * The Loader class is used to load the simulation state from a json file.
 * The class provides a method to load the simulation state, which includes the
 * robots and walls.
 *
 * @author Matus Tabi
 */

#ifndef LOADER_HPP
#define LOADER_HPP

#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "../models/automaticRobot.hpp"
#include "../models/manualRobot.hpp"
#include "../models/robotBase.hpp"
#include "../models/wall.hpp"

class Loader {
  public:
    /**
     * @brief Default constructor.
     */
    Loader();

    /**
     * @brief Default destructor.
     */
    ~Loader();

    /**
     * @brief Loads the simulation state from a json file.
     *
     * @param new_robot_vector The vector of robots to load.
     * @param new_wall_vector The vector of walls to load.
     */
    void load_simulation(std::vector<RobotBase *> &new_robot_vector,
                         std::vector<Wall *> &new_wall_vector);

  private:
    /**
     * @brief Gets the filename of the json file to load.
     *
     * @return The filename of the selected json file.
     */
    QString get_filename();

    /**
     * @brief Checks if the file is valid.
     *
     * @param file The file to check.
     */
    void check_file(QFile &file);

    /**
     * @brief Loads the robots from the json file.
     *
     * @param robots The json array of robots to load.
     * @param new_robot_vector The vector of robots to load.
     */
    void load_robots(QJsonArray &robots,
                     std::vector<RobotBase *> &new_robot_vector);

    /**
     * @brief Loads the walls from the json file.
     *
     * @param walls The json array of walls to load.
     * @param new_wall_vector The vector of walls to load.
     */
    void load_walls(QJsonArray &walls, std::vector<Wall *> &new_wall_vector);

    /**
     * @brief Creates a manual robot.
     *
     * @param position The position of the robot.
     * @param velocity The velocity of the robot.
     * @param angle The angle of the robot.
     * @param color The color of the robot.
     *
     * @return The created manual robot.
     */
    static RobotBase *create_manual_robot(const Vector2D &position,
                                          const Vector2D velocity, int angle,
                                          const QColor &color);

    /**
     * @brief Creates an automatic robot.
     *
     * @param position The position of the robot.
     * @param velocity The velocity of the robot.
     * @param angle The angle of the robot.
     * @param color The color of the robot.
     *
     * @return The created automatic robot.
     */
    static RobotBase *create_automatic_robot(const Vector2D &position,
                                             const Vector2D velocity, int angle,
                                             const QColor &color);

    /**
     * @brief The map of robot types.
     * 
     * The map of robot types is used to create robots based on their type.
     * The map contains the robot type as a key and a function pointer to the
     * function that creates the robot as a value.
     * 
     * The map contains the following robot types:
     * - ManualRobot
     * - AutomaticRobot
    */
    std::map<QString, RobotBase *(*)(const Vector2D &, const Vector2D, int,
                                     const QColor &)>
        robot_type = {
            {"ManualRobot", create_manual_robot},
            {"AutomaticRobot", create_automatic_robot},
    };
};

#endif
