/**
 * @file manualRobotStateEnum.hpp
 * @brief Definition of the ManualRobotState enum.
 *
 * The ManualRobotState enum is used to specify the state of the robot when
 * controlled manually.
 *
 * @author Matus Tabi
 */

#ifndef MANUAL_ROBOT_STATE_ENUM_HPP
#define MANUAL_ROBOT_STATE_ENUM_HPP

enum ManualRobotState {
    /**
     * @brief The robot is idle.
     */
    IDLE,

    /**
     * @brief The robot is moving forward.
     */
    MOVING,

    /**
     * @brief The robot is rotating left.
     */
    ROTATE_LEFT,

    /**
     * @brief The robot is rotating right.
     */
    ROTATE_RIGHT
};

#endif
