#include "gui.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>

GUI::GUI(QWidget *parent)
    : QMainWindow{parent}, controller{RobotController::get_instance()} {

    setStyleSheet("background-color: black;");
    setAutoFillBackground(true);

    controller->add_robot(new Robot(100, 100));
    controller->add_robot(new Robot(100, 200));
    setup_ui();
    setup_timer();
}

GUI::~GUI() {
    delete robot_view_widget;
    delete timer;
    delete controller;
}

void GUI::move_robots() {
    controller->move_robots(controller->detect_collision());
    std::vector<Robot *> robots{controller->get_robots()};
    robot_view_widget->set_robots(robots);
}

void GUI::setup_ui() {
    robot_view_widget = new RobotViewWidget(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(robot_view_widget);

    QWidget *central_widget = new QWidget(this);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);
}

void GUI::setup_timer() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GUI::move_robots);
    const int interval = 17; // 60 FPS
    timer->start(interval);
}
