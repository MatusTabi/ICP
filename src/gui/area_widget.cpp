#include "area_widget.hpp"

#include <QPainter>
#include <iostream>

#define ROBOT_ANGLE 45

AreaWidget::AreaWidget(QWidget *parent) : QWidget{parent} {}

void AreaWidget::set_models(const std::vector<Robot *> &robots,
                                 const std::vector<Wall *> &walls) {
    this->robots = robots;
    this->walls = walls;
    update();
}

void AreaWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter{this};

    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::white, 4, Qt::SolidLine));

    draw_robots(painter);
    draw_walls(painter);
}

void AreaWidget::draw_robots(QPainter &painter) {
    for (const auto &robot : robots) {
        const QPointF r_position = robot->get_position();
        const int r_size = robot->get_size();

        painter.drawEllipse(r_position, r_size, r_size);
        draw_lines(painter, r_position, r_size, robot->get_rotation_angle());
    }
}

void AreaWidget::draw_walls(QPainter &painter) {
    for (const auto &wall : walls) {
        const QPointF w_position = wall->get_position();
        const QPointF w_size = wall->get_size();
        
        painter.setPen(QPen(wall->get_color(), 4, Qt::SolidLine));
        painter.drawRect(w_position.x(), w_position.y(), w_size.x(), w_size.y());
    }
}

void AreaWidget::draw_lines(QPainter &painter, const QPointF &r_position,
                                 const int &r_size, const int &r_direction) {
    QLineF angle_line;
    angle_line.setP1(r_position);
    angle_line.setAngle(r_direction - ROBOT_ANGLE);
    angle_line.setLength(r_size);
    painter.drawLine(angle_line);

    angle_line.setAngle(r_direction + ROBOT_ANGLE);
    painter.drawLine(angle_line);
}
