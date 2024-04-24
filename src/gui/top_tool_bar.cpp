#include "top_tool_bar.hpp"

#include <iostream>

TopToolBar::TopToolBar(const QString &title, QWidget *parent)
    : QToolBar{title, parent}, controller_{Controller::get_instance()} {
    setup_actions();
    setup_connections();
}

void TopToolBar::setup_actions() {
    start_stop_ = new QAction{"Start stop simulation", this};
    start_stop_->setIcon(QIcon{"icons/play.png"});
    addAction(start_stop_);
    setIconSize(QSize{32, 32});

    addSeparator();

    wall_ = new QAction{"Add new wall", this};
    wall_->setIcon(QIcon{"icons/wall.png"});
    addAction(wall_);
    setIconSize(QSize{32, 32});

    robot_ = new QAction{"Add automatic robot", this};
    robot_->setIcon(QIcon{"icons/robot.png"});
    addAction(robot_);
    setIconSize(QSize{32, 32});

    manual_robot_ = new QAction{"Add manual robot", this};
    manual_robot_->setIcon(QIcon{"icons/manual_robot.png"});
    addAction(manual_robot_);
    setIconSize(QSize{32, 32});
}

void TopToolBar::setup_connections() {
    connect(start_stop_, &QAction::triggered, this,
            &TopToolBar::toggle_action_icon);
    connect(wall_, &QAction::triggered, this, &TopToolBar::add_wall);
    connect(robot_, &QAction::triggered, this,
            &TopToolBar::add_robot);
}

void TopToolBar::add_wall() {
    controller_->add_wall(new Wall{100, 100, 100, 100});
    emit redraw();
}

void TopToolBar::add_robot() {
    controller_->add_robot(new Robot{Vector2D{300, 300}, Vector2D{2, 0}});
    emit redraw();
}

void TopToolBar::toggle_action_icon() {
    controller_->toggle_simulation_state();

    if (controller_->is_simulation_running()) {
        start_stop_->setIcon(QIcon{"icons/stop.png"});
    } else {
        start_stop_->setIcon(QIcon{"icons/play.png"});
    }
    emit toggle_simulation();
}