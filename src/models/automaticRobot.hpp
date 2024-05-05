/**
 * @file automaticRobot.hpp
 *
 * @brief This file contains the declaration of the AutomaticRobot class.
 *
 * The file contains the declaration of the AutomaticRobot class. The class
 * inherits from the RobotBase class and represents an automatic robot.
 *
 * @author Matus Tabi
 */

#ifndef AUTOMATIC_ROBOT_HPP
#define AUTOMATIC_ROBOT_HPP

#include "robotBase.hpp"

class AutomaticRobot : public RobotBase {
  public:
    /**
     * @brief Constructor of the AutomaticRobot class with basic coordinates as
     * parameters.
     *
     * @param x The x coordinate of the robot.
     * @param y The y coordinate of the robot.
     */
    AutomaticRobot(double x, double y);

    /**
     * @brief Constructor of the AutomaticRobot class with vector as a
     * parameter.
     *
     * @param r_position The position of the robot.
     */
    AutomaticRobot(Vector2D r_position);

    /**
     * @brief Constructor of the AutomaticRobot class with position vector and
     * velocity as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     */
    AutomaticRobot(Vector2D r_position, Vector2D r_velocity);

    /**
     * @brief Constructor of the AutomaticRobot class with position vector,
     * velocity, rotation angle and color as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     * @param r_rotation_angle The rotation angle of the robot.
     * @param r_color The color of the robot.
     */
    AutomaticRobot(Vector2D r_position, Vector2D r_velocity,
                   int r_rotation_angle, QColor r_color);

    /**
     * @brief Moves the robot.
    */
    void move() override;

    /**
     * @brief Rotates the robot.
    */
    void rotate() override;

    /**
     * @brief Returns the type of the robot.
     * 
     * @return The type of the robot.
    */
    const QString type() override;
};

#endif
