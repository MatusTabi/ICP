/**
 * @file manualRobot.hpp
 *
 * @brief This file contains the declaration of the ManualRobot class.
 *
 * The class inherits from the RobotBase class and represents a manual robot.
 *
 * The manual robot is controlled by the user. The user can move the robot
 * forward, rotate it left or right, or stop it.
 *
 * @author Matus Tabi
 */

#ifndef MANUAL_ROBOT_HPP
#define MANUAL_ROBOT_HPP

#include "../utilities/manualRobotStateEnum.hpp"
#include "robotBase.hpp"
#include <cmath>

class ManualRobot : public RobotBase {
  public:
    /**
     * @brief Constructor of the ManualRobot class with basic coordinates as
     * parameters.
     *
     * @param x The x coordinate of the robot.
     * @param y The y coordinate of the robot.
     */
    ManualRobot(double x, double y);

    /**
     * @brief Constructor of the ManualRobot class with vector as a parameter.
     *
     * @param r_position The position of the robot.
     */
    ManualRobot(Vector2D r_position);

    /**
     * @brief Constructor of the ManualRobot class with position vector and
     * velocity as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     */
    ManualRobot(Vector2D r_position, Vector2D r_velocity);

    /**
     * @brief Constructor of the ManualRobot class with position vector,
     * velocity, rotation angle and color as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     * @param r_rotation_angle The rotation angle of the robot.
     * @param r_color The color of the robot.
     */
    ManualRobot(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle,
                QColor r_color);

    /**
     * @brief Moves the robot.
     *
     * The method moves the robot in the direction of the velocity vector.
     * The robot moves forward if the state is MOVING.
     */
    void move() override;

    /**
     * @brief Rotates the robot.
     *
     * The method rotates the robot left or right if the state is ROTATING_LEFT
     * or ROTATING_RIGHT.
     */
    void rotate() override;

    /**
     * @brief Returns the type of the robot.
     *
     * @return The type of the robot.
     */
    const QString type() override;

    /**
     * @brief Returns the second point of the inner circle that represents the
     * ManualRobot in simulation.
     *
     * @return The second point of the inner circle.
     */
    const Vector2D second_circle_point();

    /**
     * @brief Changes the state of the robot.
     *
     * @param new_state The new state of the robot.
     */
    void change_state(const ManualRobotState new_state);

    /**
     * @brief Returns the state of the robot.
     *
     * @return The state of the robot.
     */
    const ManualRobotState state();

  private:
    /**
     * @brief The width of the inner circle.
     */
    const double second_width = width / 2;

    /**
     * @brief The state of the robot.
     */
    ManualRobotState state_ = IDLE;
};

#endif
