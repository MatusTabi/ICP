#include "sidebar.hpp"

SideBar::SideBar(QWidget *parent) : QWidget{parent} {
    setFixedWidth(300);
}

void SideBar::paintEvent(QPaintEvent *event) {

    QPainter painter{this};
    painter.fillRect(rect(), Qt::gray);
}