/**
 * @file robotBase.hpp
 * 
 * @brief This file contains the declaration of the RobotBase class.
 * 
 * The class represents a base class for all robots.
 *
 * The class contains basic attributes and methods that are common for all
 * robots. The class is abstract and cannot be instantiated.
 *
 * @author Matus Tabi
 */

#ifndef ROBOT_BASE_HPP
#define ROBOT_BASE_HPP

#include "../utilities/robotRotationDirectionEnum.hpp"
#include "../utilities/vector2d.hpp"
#include <QColor>

class RobotBase {

  public:
    /**
     * @brief The color of the robot when it collides with an obstacle.
     */
    static const QColor CollisionColor;

    /**
     * @brief The default color of the robot.
     */
    static const QColor DefaultColor;

    /**
     * @brief The color of the robot when it is selected.
     */
    static const QColor SelectedColor;

    /**
     * @brief The default position of the robot.
     */
    static const Vector2D DefaultPosition;

    /**
     * @brief The default velocity of the robot.
     */
    static const Vector2D DefaultVelocity;

    /**
     * @brief Constructor of the RobotBase class with basic coordinates as
     * parameters.
     *
     * @param x The x coordinate of the robot.
     * @param y The y coordinate of the robot.
     */
    RobotBase(double x, double y);

    /**
     * @brief Constructor of the RobotBase class with position vector as a
     * parameter.
     *
     * @param r_position The position of the robot.
     */
    RobotBase(Vector2D r_position);

    /**
     * @brief Constructor of the RobotBase class with position vector and
     * velocity as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     */
    RobotBase(Vector2D r_position, Vector2D r_velocity);

    /**
     * @brief Constructor of the RobotBase class with position vector, velocity,
     * rotation angle and color as parameters.
     *
     * @param r_position The position of the robot.
     * @param r_velocity The velocity of the robot.
     * @param r_rotation_angle The rotation angle of the robot.
     * @param r_color The color of the robot.
     */
    RobotBase(Vector2D r_position, Vector2D r_velocity, int r_rotation_angle,
              QColor r_color);

    /**
     * @brief Destructor of the RobotBase class.
     */
    virtual ~RobotBase();

    /**
     * @brief Moves the robot.
     * Virtual method that is implemented in the derived classes.
     */
    virtual void move() = 0;

    /**
     * @brief Rotates the robot.
     * Virtual method that is implemented in the derived classes.
     */
    virtual void rotate() = 0;

    /**
     * @brief Returns the type of the robot.
     * Virtual method that is implemented in the derived classes.
     *
     * @return The type of the robot.
     */
    virtual const QString type() = 0;

    /**
     * @brief Returns the middle point of the robot.
     *
     * @return The middle point of the robot.
     */
    const Vector2D get_middle_point();

    /**
     * @brief Set the rotation flag to true.
     */
    void rotation_on();

    /**
     * @brief Set the rotation flag to false.
     */
    void rotation_off();

    /**
     * @brief Returns the rotation flag.
     *
     * @return The rotation flag.
     */
    bool &is_rotating();

    /**
     * @brief Checks if the robot contains the point.
     *
     * @param point The point to check.
     *
     * @return True if the robot contains the point, false otherwise.
     */
    bool contains(const Vector2D &point);

    /**
     * @brief Starts moving the robot.
     *
     * @param point The point to move to.
     */
    void start_moving(const Vector2D &point);

    /**
     * @brief Stops moving the robot.
     */
    void stop_moving();

    /**
     * @brief Returns the moving flag.
     *
     * @return The moving flag.
     */
    bool &is_moving();

    /**
     * @brief Rotates the robot staticly when the simulation is not running.
     *
     * @param clockwise True if the robot should rotate clockwise, false
     * otherwise.
     */
    void rotate_staticly(const bool clockwise);

    /**
     * @brief Method returns the vector of the direction line.
     *
     * @return The vector of the direction line.
     */
    const Vector2D compute_direction_line();

    /**
     * @brief Method sets the velocity of the robot.
     *
     * @param r_velocity The velocity of the robot.
     */
    void set_velocity(Vector2D r_velocity);

    /**
     * @brief Method sets the position of the robot.
     *
     * @param r_position The position of the robot.
     */
    void set_position(Vector2D r_position);

    /**
     * @brief Method sets the collision distance of the robot.
     *
     * @param r_collision_distance The collision distance of the robot.
     */
    void set_collision_distance(const int r_collision_distance);

    /**
     * @brief Method sets the angular speed of the robot.
     *
     * @param r_angular_speed The angular speed of the robot.
     */
    void set_angular_speed(const int r_angular_speed);

    /**
     * @brief Method sets the color of the robot.
     *
     * @param r_color The color of the robot.
     */
    void colorize(QColor r_color);

    /**
     * @brief Method relocates the robot to the given point.
     *
     * @param point The point to relocate the robot to.
     */
    void relocate(const Vector2D &point);

    /**
     * @brief Method sets the angle of the robot.
     *
     * @param angle The angle of the robot.
     */
    void set_angle(int angle);

    /**
     * @brief Method sets the rotation direction of the robot.
     *
     * @param direction The rotation direction of the robot.
     */
    void set_rotation_direction(const RotationDirection direction);

    /**
     * @brief Method returns the position of the robot.
     *
     * @return The position of the robot.
     */
    const Vector2D &get_position();

    /**
     * @brief Method returns the size of the robot.
     *
     * @return The size of the robot.
     */
    const double &get_size();

    /**
     * @brief Method returns the width of the robot.
     * 
     * @return The width of the robot.
    */
    const double &get_width();

    /**
     * @brief Method returns the velocity of the robot.
     *
     * @return The velocity of the robot.
     */
    const Vector2D &velocity();

    /**
     * @brief Method returns the color of the robot.
     *
     * @return The color of the robot.
     */
    const QColor &color();
    
    /**
     * @brief Method returns the collision distance of the robot.
     * 
     * @return The collision distance of the robot.
    */
    const int &collision_distance();

    /**
     * @brief Method returns the rotation angle of the robot.
     * 
     * @return The rotation angle of the robot.
    */
    const int &rotation_angle();

    /**
     * @brief Method returns the rotation direction of the robot.
     * 
     * @return The rotation direction of the robot.
    */
    const RotationDirection &rotation_direction();

    /**
     * @brief Method returns the angular speed of the robot.
     * 
     * @return The angular speed of the robot.
    */
    const int &angular_speed();

  protected:

    /**
     * @brief The robot's rotation flag.
    */
    bool rotate_flag_ = false;

    /**
     * @brief The robot's rotation angle.
    */
    int rotation_angle_ = 50;

    /**
     * @brief The robot's collision distance.
    */
    int collision_distance_ = 20;
    
    /**
     * @brief The robot's angular speed.
    */
    int angular_speed_ = 1;

    /**
     * @brief The robot's current rotation.
    */
    int current_rotation = 0;

    /**
     * @brief The robot's position.
    */
    Vector2D position_;

    /**
     * @brief The robot's velocity.
    */
    Vector2D velocity_;

    /**
     * @brief The width of the robot.
    */
    const double width = 30;

    /**
     * @brief The color of the robot.
    */
    QColor color_ = RobotBase::DefaultColor;

    /**
     * @brief The direction of the robot's rotation.
    */
    RotationDirection rotation_direction_ = RotationDirection::CLOCKWISE;

  private:

    /**
     * @brief Calculates and returns vector of the moving offset.
     * 
     * @param point The point to calculate the offset from.
     * 
     * @return The vector of the moving offset.
    */
    const Vector2D calculate_moving_offset(const Vector2D &point);

    /**
     * @brief Updates the position of the robot when moving.
     * 
     * @param point The point to update the position to.
    */
    void update_move_position(const Vector2D &point);

    /**
     * @brief The offset of the robot when moving around.
    */
    Vector2D offset;

    /**
     * @brief The flag that indicates if the robot is moving.
    */
    bool moving_ = false;
};

#endif
