#include "gui.hpp"

#include <QAction>
#include <QDir>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QTimer>
#include <QToolBar>
#include <QWidget>
#include <iostream>

GUI::GUI(QWidget *parent)
    : QMainWindow{parent}, controller_{Controller::get_instance()} {

    setStyleSheet("background-color: #181825;");
    setWindowTitle(tr("2D Robot Simulator"));

    setup_ui();
    setup_connections();
}

GUI::~GUI() {
    delete area_widget;
    delete controller_;
}

void GUI::setup_ui() {
    area_widget = new AreaWidget(this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(area_widget);

    side_bar = new SideBar(this);
    layout->addWidget(side_bar);

    menu_bar = new MenuBar(this);
    setMenuBar(menu_bar);

    QWidget *central_widget = new QWidget(this);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);
}

void GUI::setup_connections() {
    connect(side_bar, &SideBar::toggle_simulation, area_widget,
            &AreaWidget::toggle_timer);
    connect(side_bar, &SideBar::redraw, area_widget, &AreaWidget::redraw);
    connect(menu_bar, &MenuBar::load_simulation, area_widget,
            &AreaWidget::redraw);
    connect(area_widget, &AreaWidget::show_robot_overview, side_bar,
            &SideBar::show_robot_overview_slot);
    connect(menu_bar, &MenuBar::redraw, area_widget, &AreaWidget::redraw);
    connect(area_widget, &AreaWidget::stop, side_bar, &SideBar::stop_simulation);
}
