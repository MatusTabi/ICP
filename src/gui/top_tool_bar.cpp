#include "top_tool_bar.hpp"

#include <iostream>

TopToolBar::TopToolBar(const QString &title, QWidget *parent)
    : QToolBar{title, parent}, controller_{Controller::get_instance()} {
    setup_actions();
    setup_connections();
}

void TopToolBar::setup_actions() {
    start_stop_action = new QAction{"Start stop simulation", this};
    start_stop_action->setIcon(QIcon{"icons/play.png"});
    addAction(start_stop_action);
    setIconSize(QSize{32, 32});

    addSeparator();

    add_wall_action = new QAction{"Add new wall", this};
    add_wall_action->setIcon(QIcon{"icons/wall.png"});
    addAction(add_wall_action);
    setIconSize(QSize{32, 32});

    add_robot_action = new QAction{"Add new robot", this};
    add_robot_action->setIcon(QIcon{"icons/robot.png"});
    addAction(add_robot_action);
    setIconSize(QSize{32, 32});
}

void TopToolBar::setup_connections() {
    connect(start_stop_action, &QAction::triggered, this,
            &TopToolBar::toggle_action_icon);
    connect(add_wall_action, &QAction::triggered, this, &TopToolBar::add_wall);
}

void TopToolBar::toggle_action_icon() {
    controller_->toggle_simulation_state();

    if (controller_->is_simulation_running()) {
        start_stop_action->setIcon(QIcon{"icons/stop.png"});
    } else {
        start_stop_action->setIcon(QIcon{"icons/play.png"});
    }
    emit toggle_simulation();
}