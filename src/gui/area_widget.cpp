#include "area_widget.hpp"
#include "../utilities/vector2d.hpp"

#include <cmath>
#include <iostream>

#define ROBOT_ANGLE 45

AreaWidget::AreaWidget(QWidget *parent)
    : QWidget{parent}, controller_{Controller::get_instance()} {
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    redraw();
    setup_timer();
}

AreaWidget::~AreaWidget() {
    delete timer;
}

void AreaWidget::set_models(const std::vector<Robot *> &robots,
                            const std::vector<Wall *> &walls) {
    this->robots = robots;
    this->walls = walls;
}

void AreaWidget::setup_timer() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AreaWidget::update_position);
}

void AreaWidget::update_position() {
    controller_->move_robots();
    redraw();
}

void AreaWidget::toggle_timer() {
    if (timer->isActive()) {
        timer->stop();
    } else {
        timer->start(kInterval);
    }
}

void AreaWidget::redraw() {
    set_models(controller_->get_robots(), controller_->get_walls());
    update();
}

void AreaWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_P) {
        emit pause();
    } else if (event->key() == Qt::Key_E) {
        controller_->rotate_robot_staticly(true);
        redraw();
    } else if (event->key() == Qt::Key_Q) {
        controller_->rotate_robot_staticly(false);
        redraw();
    }
}

void AreaWidget::mousePressEvent(QMouseEvent *event) {
    if (controller_->is_simulation_running()) {
        return;
    }
    const Vector2D position{event->pos()};
    if (controller_->select_robot(position)) {
        redraw();
        return;
    }
    controller_->reset_robots();
    redraw();
    if (controller_->select_wall(position)) {
        redraw();
    }
}

void AreaWidget::mouseMoveEvent(QMouseEvent *event) {
    if (controller_->is_simulation_running()) {
        return;
    }
    const Vector2D position{event->pos()};
    if (controller_->can_move_selected_robot(position)) {
        redraw();
        return;
    }
    setCursor(controller_->get_cursor_shape(position));
    if (controller_->can_move_selected_wall(position)) {
        redraw();
    }
}

void AreaWidget::mouseReleaseEvent(QMouseEvent *event) {
    controller_->deselect();
}

void AreaWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    update();
}

void AreaWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter{this};
    painter.fillRect(rect(), Qt::white);

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
        const Vector2D w_position = wall->position();
        const Vector2D w_size = wall->size();

        painter.setPen(QPen(wall->color(), 4, Qt::SolidLine));
        painter.drawRect(w_position.x_, w_position.y_, w_size.x_, w_size.y_);
    }
}

void AreaWidget::draw_border(QPainter &painter) {
    QPen pen(Qt::black, 4, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(rect());
}
