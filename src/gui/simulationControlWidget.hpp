/**
 * @file simulationControlWidget.hpp
 * 
 * @brief This file contains the declaration of the SimulationControlWidget class.
 * 
 * The class represents a widget that displays the simulation control buttons.
 * 
 * @author Matus Tabi
*/

#ifndef SIMULATION_CONTROL_HPP
#define SIMULATION_CONTROL_HPP

#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "../controllers/controller.hpp"

class SimulationControlWidget : public QWidget {
    Q_OBJECT
  public:

    /**
     * @brief Constructor of the SimulationControlWidget class.
    */
    SimulationControlWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the SimulationControlWidget class.
    */
    ~SimulationControlWidget();

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
   * @brief Toggle the simulation.
  */
    void toggle_simulation_slot();

  protected:
  /**
   * @brief Paints the widget.
   * 
   * @param event The paint event.
  */
    void paintEvent(QPaintEvent *event) override;

  private slots:

  /**
   * @brief Adds an auto robot to the simulation.
  */
    void add_auto_robot();

    /**
     * @brief Adds a manual robot to the simulation.
    */
    void add_manual_robot();

    /**
     * @brief Adds a wall to the simulation.
    */
    void add_wall();

  private:

  /**
   * @brief Sets up the connections between the widgets.
  */
    void setup_connections();

    /**
     * @brief The controller of the application.
    */
    Controller *controller_;

    /**
     * @brief The play button icon.
    */
    const QIcon play_icon_{"icons/play.png"};

    /**
     * @brief The pause button icon.
    */
    const QIcon stop_icon_{"icons/stop.png"};

    /**
     * @brief The auto robot icon.
    */
    const QIcon auto_robot_icon_{"icons/auto_robot.png"};

    /**
     * @brief The manual robot icon.
    */
    const QIcon manual_robot_icon_{"icons/manual_robot.png"};

    /**
     * @brief The wall icon.
    */
    const QIcon wall_icon_{"icons/wall.png"};

    /**
     * @brief The play button.
    */
    QPushButton *toggle_sim_button_;

    /**
     * @brief The auto robot button.
    */
    QPushButton *auto_robot_button_;

    /**
     * @brief The manual robot button.
    */
    QPushButton *manual_robot_button_;

    /**
     * @brief The wall button.
    */
    QPushButton *wall_button_;
};

#endif
