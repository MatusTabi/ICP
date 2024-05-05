/**
 * @file wallEdgeEnum.hpp
 *
 * @brief The file contains the declaration of the Edge enum.
 *
 * The enum represents the edges of the wall.
 *
 * @author Matus Tabi
 */

#ifndef WALL_EDGE_ENUM_HPP
#define WALL_EDGE_ENUM_HPP

enum Edge {
    /**
     * @brief No edge is near the point.
     */
    None,
    /**
     * @brief The left edge is near the point.
     */
    Left,

    /**
     * @brief The right edge is near the point.
     */
    Right,

    /**
     * @brief The top edge is near the point.
     */
    Top,

    /**
     * @brief The bottom edge is near the point.
     */
    Bottom
};

#endif
