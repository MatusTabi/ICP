#ifndef GUI_HPP
#define GUI_HPP

#include "../controllers/robot_controller.hpp"
#include "area_widget.hpp"
#include "select_widget.hpp"
#include <QElapsedTimer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GUI;
}
QT_END_NAMESPACE
class GUI : public QMainWindow {
    Q_OBJECT
  public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

  private slots:
    void move_robots();

  private:
    void setup_timer();
    void setup_ui();

    RobotController *controller;
    QTimer *timer;
    AreaWidget *area_widget;
    SelectWidget *select_widget;
    Ui::GUI *ui;
};

#endif
