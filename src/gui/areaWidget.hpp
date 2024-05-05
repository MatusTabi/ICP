/**
 * @file areaWidget.hpp
 *
 * @brief The file contains the declaration of the AreaWidget class. 
 * 
 * The class represents a widget that displays the simulation area.
 *
 * @author Matus Tabi
 */

#ifndef ROBOT_VIEW_WIDGET_HPP
#define ROBOT_VIEW_WIDGET_HPP

#include "../controllers/controller.hpp"
#include "../models/robotBase.hpp"
#include "../models/wall.hpp"
#include "../utilities/vector2d.hpp"
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

class AreaWidget : public QWidget {
    Q_OBJECT
  public:
    /**
     * @brief Constructor of the AreaWidget class.
     */
    AreaWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the AreaWidget class.
     */
    ~AreaWidget();

    /**
     * @brief Sets the models that will be displayed in the widget.
     *
     * @param robots The robots that will be displayed.
     * @param walls The walls that will be displayed.
     */
    void set_models(const std::vector<RobotBase *> &robots,
                    const std::vector<Wall *> &walls);

  signals:
    /**
     * @brief Signal that is emitted when the simulation is stopped.
     */
    void stop();

    /**
     * @brief Signal that is emitted when the robot's overview needs to be
     * displayed.
     */
    void show_robot_overview();

  public slots:

    /**
     * @brief Toggles the timer that updates the widget.
    */
    void toggle_timer();

    /**
     * @brief Redraws the widget.
    */
    void redraw();

  protected:
    /**
     * @brief Paints the widget.
     * 
     * @param event The paint event.
    */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief Shows the widget.
     * 
     * @param event The show event.
    */
    void showEvent(QShowEvent *event) override;
    
    /**
     * @brief Handles the key press event.
     * 
     * @param event The key event.
    */
    void keyPressEvent(QKeyEvent *event) override;

    /**
     * @brief Handles the mouse press event.
     * 
     * @param event The mouse event.
    */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Handles the mouse move event.
     * 
     * @param event The mouse event.
    */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief Handles the mouse release event.
     * 
     * @param event The mouse event.
    */
    void mouseReleaseEvent(QMouseEvent *event) override;

  private slots:
    
    /**
     * @brief Updates the position of the robots.
    */
    void update_position();

  private:

    /**
     * @brief Sets up the timer that updates the widget.
    */
    void setup_timer();

    /**
     * @brief Draws the robots.
    */
    void draw_robots(QPainter &painter);

    /**
     * @brief Draws the walls.
    */
    void draw_walls(QPainter &painter);

    /**
     * @brief Draws the border of the simulation area.
    */
    void draw_border(QPainter &painter);

    /**
     * @brief Interval of the timer.
    */
    const int kInterval{17};

    /**
     * @brief Vector of the robots.
    */
    std::vector<RobotBase *> robots;

    /**
     * @brief Vector of the walls.
    */
    std::vector<Wall *> walls;

    /**
     * @brief Timer that updates the widget.
    */
    QTimer *timer;

    /**
     * @brief The controller of the simulation.
    */
    Controller *controller_;
};

#endif
