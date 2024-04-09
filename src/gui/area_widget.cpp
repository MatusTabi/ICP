#include "area_widget.hpp"
#include "../utilities/vector2d.hpp"

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

    draw_robots(painter);
    draw_walls(painter);
    draw_border(painter);
}

void AreaWidget::draw_robots(QPainter &painter) {
    for (const auto &robot : robots) {
        painter.setPen(QPen(robot->color(), 4, Qt::SolidLine));
        const Vector2D r_position = robot->get_position();
        const Vector2D line = robot->compute_direction_line();
        const Vector2D middle_point = robot->get_middle_point();
        const double r_width = robot->get_width();

        painter.drawEllipse(r_position.x_, r_position.y_, r_width, r_width);
        painter.drawLine(middle_point.x_, middle_point.y_, line.x_, line.y_);
    }
}

void AreaWidget::draw_walls(QPainter &painter) {
    for (const auto &wall : walls) {
        const Vector2D w_position = wall->get_position();
        const Vector2D w_size = wall->get_size();

        painter.setPen(QPen(wall->get_color(), 4, Qt::SolidLine));
        painter.drawRect(w_position.x_, w_position.y_, w_size.x_, w_size.y_);
    }
}

void AreaWidget::draw_border(QPainter &painter) {
    painter.drawRect(rect());
}
