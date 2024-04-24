#include "gui.hpp"

#include <QAction>
#include <QDir>
#include <QHBoxLayout>
#include <QTimer>
#include <QToolBar>
#include <QDockWidget>
#include <QMenuBar>
#include <QWidget>
#include <iostream>

GUI::GUI(QWidget *parent)
    : QMainWindow{parent}, controller_{Controller::get_instance()} {

    setStyleSheet("background-color: #ddd8d3;");
    setWindowTitle(tr("2D Robot Simulator"));

    setup_ui();
    setup_connections();
}

GUI::~GUI() {
    delete area_widget;
    delete top_tool_bar;
    delete controller_;
}

void GUI::setup_ui() {
    area_widget = new AreaWidget(this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(area_widget);
    
    top_tool_bar = new TopToolBar(tr("ToolBar"), this);
    addToolBar(top_tool_bar);

    menu_bar = new MenuBar(this);
    setMenuBar(menu_bar);

    QWidget *central_widget = new QWidget(this);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);
}

void GUI::setup_connections() {
    connect(top_tool_bar, &TopToolBar::toggle_simulation, area_widget, &AreaWidget::toggle_timer);
    connect(area_widget, &AreaWidget::pause, top_tool_bar, &TopToolBar::toggle_action_icon);
    connect(top_tool_bar, &TopToolBar::redraw, area_widget, &AreaWidget::redraw);
    connect(menu_bar, &MenuBar::load_simulation, area_widget, &AreaWidget::redraw);
}
