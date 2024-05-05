/**
 * @file vector2d.hpp
 * @brief Definition of the Vector2D struct.
 *
 * The Vector2D struct is a simple 2D vector class that provides basic vector
 * operations such as addition, subtraction, multiplication, normalization, and
 * dot product.
 *
 * @author Matus Tabi
 */

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <QPoint>
#include <iostream>

struct Vector2D {
    /**
     * @brief The x component of the vector.
     */
    double x_;
    /**
     * @brief The y component of the vector.
     */
    double y_;

    /**
     * @brief Default constructor. Initializes the vector to (0, 0).
     */
    Vector2D();
    /**
     * @brief Constructor that initializes the vector to the given x and y
     * values.
     *
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     */
    Vector2D(double x, double y);

    /**
     * @brief Constructor that initializes the vector to the given QPoint.
     * Used for converting QPoint to Vector2D when clicking with the mouse.
     *
     * @param point The QPoint to initialize the vector with.
     */
    Vector2D(const QPoint &point);

    /**
     * @brief Overloaded multiplication operator for multiplying the vector by a
     * scalar.
     *
     * @param scalar The scalar (double) to multiply the vector by.
     * @return The resulting vector.
     */
    const Vector2D operator*(double scalar) const;

    /**
     * @brief Overloaded multiplication operator for multiplying the vector by a
     * scalar.
     *
     * @param scalar The scalar (int) to multiply the vector by.
     * @return The resulting vector.
     */
    const Vector2D operator*(int scalar) const;

    /**
     * @brief Overloaded multiplication assignment operator for multiplying the
     * vector by a scalar.
     *
     * @param scalar The scalar (double) to multiply the vector by.
     * @return The resulting vector.
     */
    const Vector2D &operator*=(double scalar);

    /**
     * @brief Overloaded multiplication assignment operator for multiplying the
     * vector by a scalar.
     *
     * @param scalar The scalar (int) to multiply the vector by.
     * @return The resulting vector.
     */
    const Vector2D &operator*=(int scalar);

    /**
     * @brief Overloaded addition operator for adding a scalar to the vector.
     *
     * @param scalar The scalar (double) to add to the vector.
     * @return The resulting vector.
     */
    const Vector2D operator+(int scalar) const;

    /**
     * @brief Overloaded addition operator for adding a vector to the vector.
     *
     * @param vector2d The vector to add to the vector.
     * @return The resulting vector.
     */
    const Vector2D operator+(const Vector2D &vector2d) const;

    /**
     * @brief Overloaded addition assignment operator for adding a vector to the
     * vector.
     *
     * @param vector2d The vector to add to the vector.
     * @return The resulting vector.
     */
    const Vector2D &operator+=(const Vector2D &vector2d);

    /**
     * @brief Overloaded subtraction operator for subtracting a vector from the
     * vector.
     * 
     * @param vector2d The vector to subtract from the vector.
     * @return The resulting vector.
    */
    const Vector2D operator-(const Vector2D &vector2d) const;

    /**
     * @brief Normalizes the vector.
     * 
     * @return The normalized vector.
    */
    const Vector2D normalize();

    /**
     * @brief Returns the length of the vector.
     * 
     * @return The length of the vector.
    */
    const double length();

    /**
     * @brief Returns the dot product of the vector and another vector.
     * 
     * @param other The other vector to calculate the dot product with.
     * 
     * @return The dot product of the two vectors.
    */
    const double dot(const Vector2D &other) const;

    /**
     * @brief Overloaded output stream operator for printing the vector.
     * 
     * @param os The output stream to print to.
     * @param vector2d The vector to print.
     * 
     * @return The output stream.
    */
    friend std::ostream &operator<<(std::ostream &os, const Vector2D &vector2d);
};

#endif
