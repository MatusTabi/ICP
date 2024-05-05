/**
 * @file wall.hpp
 *
 * @brief This file contains the declaration of the Wall class.
 * 
 * The class represents a wall in the simulation.
 *
 * @author Matus Tabi
 */

#ifndef WALL_HPP
#define WALL_HPP

#include "../utilities/vector2d.hpp"
#include "../utilities/wallEdgeEnum.hpp"

#include <QColor>

class Wall {
  public:
    /**
     * @brief The default color of the wall.
     */
    static const QColor DefaultColor;

    /**
     * @brief The color of the wall when it is selected.
     */
    static const QColor SelectedColor;

    /**
     * @brief The default position of the wall.
     */
    static const Vector2D DefaultPosition;

    /**
     * @brief The default size of the wall.
     */
    static const Vector2D DefaultSize;

    /**
     * @brief Constructor of the Wall class with basic coordinates as
     * parameters.
     *
     * @param x The x coordinate of the wall.
     * @param y The y coordinate of the wall.
     */
    Wall(double x, double y);

    /**
     * @brief Constructor of the Wall class with position vector as a parameter.
     *
     * @param w_position The position of the wall.
     */
    Wall(Vector2D w_position);

    /**
     * @brief Constructor of the Wall class with position vector and size as
     * parameters.
     *
     * @param w_position The position of the wall.
     * @param w_size The size of the wall.
     */
    Wall(Vector2D w_position, Vector2D w_size);

    /**
     * @brief Constructor of the Wall class with position vector, size and color
     * as parameters.
     *
     * @param w_position The position of the wall.
     * @param w_size The size of the wall.
     * @param color The color of the wall.
     */
    Wall(Vector2D w_position, Vector2D w_size, QColor color);

    /**
     * @brief Destructor of the Wall class.
    */
    ~Wall() = default;

    /**
     * @brief Getter for the position of the wall.
     * 
     * @return The position of the wall.
    */
    const Vector2D &position();

    /**
     * @brief Getter for the size of the wall.
     * 
     * @return The size of the wall.
    */
    const Vector2D &size();

    /**
     * @brief Getter for the color of the wall.
     * 
     * @return The color of the wall.
    */
    const QColor &color();

    /**
     * @brief Checks if the wall contains the given point.
     * 
     * @param point The point to check.
     * 
     * @return True if the wall contains the point, false otherwise.
    */
    bool contains(const Vector2D &point);

    /**
     * @brief Starts moving the wall.
     * 
     * @param point The point to move to.
    */
    void start_moving(const Vector2D &point);

    /**
     * @brief Starts resizing the wall.
     * 
     * @param point The point to resize to.
     * @param edge The edge to resize.
    */
    void start_resizing(const Vector2D &point, const Edge &edge);

    /**
     * @brief Stops moving the wall.
    */
    void stop_moving();

    /**
     * @brief Stops resizing the wall.
    */
    void stop_resizing();

    /**
     * @brief Checks if the edge is near the point.
     * 
     * @param point The point to check.
     * 
     * @return The edge near the point.
    */
    Edge is_near_edge(const Vector2D &point) const;

    /**
     * @brief Colorizes the wall with the given color.
     * 
     * @param color The color to colorize the wall with.
    */
    void colorize(const QColor &color);

    /**
     * @brief Relocates the wall to the given point.
     * 
     * @param point The point to relocate the wall to.
    */
    void relocate(const Vector2D &point);

    /**
     * @brief Resizes the wall to the given point.
     * 
     * @param point The point to resize the wall to.
    */
    void resize(const Vector2D &point);

    /**
     * @brief Getter for the moving flag.
     * 
     * @return The moving flag.
    */
    bool &is_resizing();

  private:

  /**
   * @brief Calculates the offset for relocating the wall.
   * 
   * @param point The point to calculate the offset from.
   * 
   * @return The offset for relocating the wall.
  */
    const Vector2D calculate_relocate_offset(const Vector2D &point);

    /**
     * @brief Calculates the offset for resizing the wall.
     * 
     * @param point The point to calculate the offset from.
     * 
     * @return The offset for resizing the wall.
    */
    const Vector2D calculate_resizing_offset(const Vector2D &point);

    /**
     * @brief Updates the position of the wall when relocating.
     * 
     * @param point The point to update the position to.
    */
    void update_relocate_position(const Vector2D &point);

    /**
     * @brief Updates the position of the wall when resizing.
     * 
     * @param point The point to update the position to.
    */
    void update_resize_position(const Vector2D &point);

    /**
     * @brief The position of the wall.
    */
    Vector2D position_;

    /**
     * @brief The size of the wall.
    */
    Vector2D size_;
    
    /**
     * @brief The offset of the wall when relocating.
    */
    Vector2D offset;

    /**
     * @brief The color of the wall.
    */
    QColor color_ = DefaultColor;

    /**
     * @brief The flag that indicates if the wall is resizing.
    */
    bool moving_ = false;

    /**
     * @brief The flag that indicates if the wall is resizing.
    */
    bool resizing_ = false;

    /**
     * @brief The edge that is being resized.
    */
    Edge resizing_edge_;
};

#endif
