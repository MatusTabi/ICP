#ifndef GUI_H
#define GUI_H

#include "../controllers/robot_controller.h"
#include "robot_view_widget.h"
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
    RobotViewWidget *robot_view_widget;
};

#endif
