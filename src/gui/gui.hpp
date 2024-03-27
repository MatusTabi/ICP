#ifndef GUI_HPP
#define GUI_HPP

#include "../controllers/robot_controller.hpp"
#include "area_widget.hpp"
#include <QElapsedTimer>
#include <QMainWindow>

class GUI : public QMainWindow {
    Q_OBJECT
  public:
    explicit GUI(QWidget *parent = nullptr);
    ~GUI();

  private slots:
    void move_robots();

  private:
    void setup_timer();
    void setup_ui();

    RobotController *controller;
    QTimer *timer;
    AreaWidget *area_widget;
};

#endif
