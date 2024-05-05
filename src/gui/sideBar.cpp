#include "sideBar.hpp"

SideBar::SideBar(QWidget *parent) : QWidget{parent} {
    setFixedWidth(400);
    QVBoxLayout *layout = new QVBoxLayout(this);
    simulation_control_ = new SimulationControlWidget(this);
    robot_overview_ = new RobotOverviewWidget(this);
    layout->addWidget(simulation_control_);
    layout->addWidget(robot_overview_);
    layout->setAlignment(simulation_control_, Qt::AlignCenter);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);

    setup_connections();
}

SideBar::~SideBar() {}

void SideBar::paintEvent(QPaintEvent *event) {}

void SideBar::setup_connections() {
    connect(simulation_control_, &SimulationControlWidget::toggle_simulation,
            this, &SideBar::toggle_simulation_slot);
    connect(simulation_control_, &SimulationControlWidget::redraw, this,
            &SideBar::redraw_simulation);
    connect(robot_overview_, &RobotOverviewWidget::redraw, this,
            &SideBar::redraw_simulation);
}

void SideBar::redraw_simulation() { emit redraw(); }

void SideBar::toggle_simulation_slot() {
    robot_overview_->robot_overview();
    emit toggle_simulation();
}

void SideBar::show_robot_overview_slot() { robot_overview_->robot_overview(); }

void SideBar::stop_simulation() { simulation_control_->toggle_simulation_slot(); }
