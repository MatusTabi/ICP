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

    // controller_->add_robot_vector(std::vector<Robot *>{
        // new Robot(Vector2D{300, 300}, Vector2D{2, 0}),
    // });

    // controller_->add_wall(new Wall(0, 0, 1000, 202));
    // controller_->add_wall(new Wall(0, 200, 200, 800));
    // controller_->add_wall(new Wall(800, 200, 200, 800));
    // controller_->add_wall(new Wall(200, 800, 600, 200));

    setup_ui();
    // setup_timer();
    setup_connections();
}

GUI::~GUI() {
    delete area_widget;
    delete top_tool_bar;
    // delete select_widget;
    // delete timer;
    delete controller_;
}

void GUI::setup_ui() {
    area_widget = new AreaWidget(this);
    
    // sidebar = new SideBar(this);

    QHBoxLayout *layout = new QHBoxLayout;
    // layout->addWidget(sidebar);
    layout->addWidget(area_widget);
    
    top_tool_bar = new TopToolBar(tr("ToolBar"), this);
    addToolBar(top_tool_bar);

    // QMenuBar *menu_bar = new QMenuBar(this);
    // menu_bar->addMenu(tr("File"));
    // setMenuBar(menu_bar);

    QWidget *central_widget = new QWidget(this);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);
}

void GUI::setup_connections() {
    connect(top_tool_bar, &TopToolBar::toggle_simulation, area_widget, &AreaWidget::toggle_timer);
    connect(area_widget, &AreaWidget::pause, top_tool_bar, &TopToolBar::toggle_action_icon);
    connect(top_tool_bar, &TopToolBar::add_wall, area_widget, &AreaWidget::add_wall);
}
