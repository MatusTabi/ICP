#include "robot_view_widget.h"

#include <QPainter>
#include <iostream>

#define ROBOT_ANGLE 45

RobotViewWidget::RobotViewWidget(QWidget *parent) : QWidget{parent} {}

void RobotViewWidget::set_robots(const std::vector<Robot *> &robots) {
    this->robots = robots;
    update();
}

void RobotViewWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter{this};

    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::white, 4, Qt::SolidLine));

    for (const auto &robot : robots) {
        const QPointF r_position = robot->get_position();
        const int r_size = robot->get_size();

        painter.drawEllipse(r_position, r_size, r_size);
        draw_lines(painter, r_position, r_size, robot->get_rotation_angle());
    }
}

void RobotViewWidget::draw_lines(QPainter &painter, const QPointF &r_position,
                                 const int &r_size, const int &r_direction) {
    QLineF angle_line;
    angle_line.setP1(r_position);
    angle_line.setAngle(r_direction - ROBOT_ANGLE);
    angle_line.setLength(r_size);
    painter.drawLine(angle_line);

    angle_line.setAngle(r_direction + ROBOT_ANGLE);
    painter.drawLine(angle_line);
}
