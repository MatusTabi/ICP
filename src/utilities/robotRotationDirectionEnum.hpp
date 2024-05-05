/**
 * @file robotRotationDirectionEnum.hpp
 * @brief Definition of the RotationDirection enum.
 *
 * The RotationDirection enum is used to specify the direction in which the
 * robot should rotate.
 *
 * @author Matus Tabi
 */

#ifndef ROBOT_ROTATION_DIRECTION_ENUM_HPP
#define ROBOT_ROTATION_DIRECTION_ENUM_HPP

enum RotationDirection {
    /**
     * @brief The robot should rotate clockwise.
     */
    CLOCKWISE,

    /**
     * @brief The robot should rotate counterclockwise.
     */
    COUNTERCLOCKWISE
};

#endif
