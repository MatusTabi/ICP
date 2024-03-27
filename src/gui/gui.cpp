#include "gui.hpp"

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
    controller->add_wall(new Wall(500, 50, 150, 100));
    setup_ui();
    setup_timer();
}

GUI::~GUI() {
    delete area_widget;
    delete timer;
    delete controller;
}

void GUI::move_robots() {
    controller->move_robots();

    std::vector<Robot *> robots{controller->get_robots()};
    std::vector<Wall *> walls{controller->get_walls()};

    area_widget->set_models(robots, walls);
}

void GUI::setup_ui() {
    area_widget = new AreaWidget(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(area_widget);

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
