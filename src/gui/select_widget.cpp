#include "select_widget.hpp"
#include <iostream>

SelectWidget::SelectWidget(QWidget *parent) : QWidget{parent} {}

SelectWidget::~SelectWidget() {}

void SelectWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::lightGray);

    // BORDER
    // QPen pen(Qt::red, 2);
    // painter.setPen(pen);
    // painter.drawRect(rect());
}
