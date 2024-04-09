#include "gui.hpp"
#include "../../ui_gui.h"

#include <QHBoxLayout>
#include <QTimer>
#include <QWidget>
#include <iostream>

GUI::GUI(QWidget *parent)
    : QMainWindow{parent}, controller{RobotController::get_instance()} {

    setStyleSheet("background-color: black;");

    controller->add_robot(new Robot(Vector2D{300, 300}, Vector2D(2, 0)));
    controller->add_robot(new Robot(Vector2D{500, 500}, Vector2D(0, 2)));

    controller->add_wall(new Wall(0, 0, 1000, 202));
    controller->add_wall(new Wall(0, 200, 200, 800));
    controller->add_wall(new Wall(800, 200, 200, 800));
    controller->add_wall(new Wall(200, 800, 600, 200));
    
    setup_ui();
    setup_timer();
}

GUI::~GUI() {
    delete area_widget;
    delete select_widget;
    // delete timer;
    delete controller;
}

void GUI::move_robots() {
    controller->move_robots();

    std::vector<Robot *> robots{controller->get_robots()};
    std::vector<Wall *> walls{controller->get_walls()};

    area_widget->set_models(robots, walls);
}

void GUI::setup_ui() {
    select_widget = new SelectWidget(this);
    area_widget = new AreaWidget(this);
    select_widget->setMaximumWidth(300);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(area_widget);
    layout->addWidget(select_widget);

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
