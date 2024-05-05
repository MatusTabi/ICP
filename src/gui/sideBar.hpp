/**
 * @file sideBar.hpp
 *
 * @brief The file contains the declaration of the SideBar class.
 *
 * The class represents a widget that displays the sidebar of the application.
 *
 * The sidebar contains the simulation control widget and the robot overview
 * widget.
 *
 * @author Matus Tabi
 */

#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP

#include <QPainter>
#include <QVBoxLayout>
#include <QWidget>

#include "robotOverviewWidget.hpp"
#include "simulationControlWidget.hpp"

class SideBar : public QWidget {
    Q_OBJECT
  public:
    /**
     * @brief Constructor of the SideBar class.
     */
    SideBar(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the SideBar class.
     */
    ~SideBar();

  signals:
    /**
     * @brief Signal that is emitted when the simulation is toggled.
     */
    void toggle_simulation();

    /**
     * @brief Signal that is emitted when the robot's overview needs to be
     * displayed.
     */
    void redraw();

  public slots:
    /**
     * @brief Shows the robot's overview.
     */
    void show_robot_overview_slot();

    /**
     * @brief Stops the simulation.
     */
    void stop_simulation();

  protected:
    /**
     * @brief Paints the widget.
     *
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

  private slots:
    /**
     * @brief Toggles the simulation.
     */
    void toggle_simulation_slot();

    /**
     * @brief Redraws the simulation.
     */
    void redraw_simulation();

  private:
    /**
     * @brief Sets up the connections between the widgets.
     */
    void setup_connections();

    /**
     * @brief The simulation control widget.
     */
    SimulationControlWidget *simulation_control_;

    /**
     * @brief The robot overview widget.
     */
    RobotOverviewWidget *robot_overview_;
};

#endif
