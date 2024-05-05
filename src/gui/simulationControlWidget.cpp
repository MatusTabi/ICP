#include "simulationControlWidget.hpp"
#include <iostream>

SimulationControlWidget::SimulationControlWidget(QWidget *parent)
    : QWidget{parent}, controller_{Controller::get_instance()} {

    setFixedSize(350, 100);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Simulation Control", this);
    label->setStyleSheet(
        "color: white; font-size: 20px; background-color: #1E1E3C;");
    layout->addWidget(label);
    layout->setAlignment(label, Qt::AlignCenter);

    QHBoxLayout *button_layout = new QHBoxLayout;
    button_layout->setAlignment(Qt::AlignJustify);

    toggle_sim_button_ = new QPushButton(this);
    toggle_sim_button_->setFixedSize(32, 32);
    toggle_sim_button_->setIcon(play_icon_);
    toggle_sim_button_->setIconSize(QSize(32, 32));
    toggle_sim_button_->setFocusPolicy(Qt::ClickFocus);
    button_layout->addWidget(toggle_sim_button_);

    auto_robot_button_ = new QPushButton(this);
    auto_robot_button_->setFixedSize(32, 32);
    auto_robot_button_->setIcon(auto_robot_icon_);
    auto_robot_button_->setIconSize(QSize(32, 32));
    button_layout->addWidget(auto_robot_button_);

    manual_robot_button_ = new QPushButton(this);
    manual_robot_button_->setFixedSize(32, 32);
    manual_robot_button_->setIcon(manual_robot_icon_);
    manual_robot_button_->setIconSize(QSize(32, 32));
    button_layout->addWidget(manual_robot_button_);

    wall_button_ = new QPushButton(this);
    wall_button_->setFixedSize(32, 32);
    wall_button_->setIcon(wall_icon_);
    wall_button_->setIconSize(QSize(32, 32));
    button_layout->addWidget(wall_button_);

    layout->addLayout(button_layout);

    setup_connections();
}

SimulationControlWidget::~SimulationControlWidget() {}

void SimulationControlWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), QColor(30, 30, 60));
    QPen pen(Qt::black, 4, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(rect());
}

void SimulationControlWidget::setup_connections() {
    connect(toggle_sim_button_, &QPushButton::clicked, this,
            &SimulationControlWidget::toggle_simulation_slot);
    connect(auto_robot_button_, &QPushButton::clicked, this,
            &SimulationControlWidget::add_auto_robot);
    connect(wall_button_, &QPushButton::clicked, this,
            &SimulationControlWidget::add_wall);
    connect(manual_robot_button_, &QPushButton::clicked, this,
            &SimulationControlWidget::add_manual_robot);
}

void SimulationControlWidget::add_manual_robot() {
    if (!controller_->is_simulation_running()) {
        controller_->add_robot(
            new ManualRobot{Vector2D{RobotBase::DefaultPosition}, Vector2D{2, 0}});
        emit redraw();
    }
}

void SimulationControlWidget::add_wall() {
    if (!controller_->is_simulation_running()) {
        controller_->add_wall(new Wall{Vector2D{Wall::DefaultPosition},
                                       Vector2D{Wall::DefaultSize}});
        emit redraw();
    }
}

void SimulationControlWidget::add_auto_robot() {
    if (!controller_->is_simulation_running()) {
        controller_->add_robot(
            new AutomaticRobot{Vector2D{RobotBase::DefaultPosition},
                               Vector2D{RobotBase::DefaultVelocity}});
        emit redraw();
    }
}

void SimulationControlWidget::toggle_simulation_slot() {
    controller_->toggle_simulation_state();
    if (controller_->is_simulation_running()) {
        toggle_sim_button_->setIcon(stop_icon_);
    } else {
        toggle_sim_button_->setIcon(play_icon_);
    }
    controller_->deselect_robot();
    emit toggle_simulation();
}
