#ifndef WALL_HPP
#define WALL_HPP

#include <QPoint>

class Wall {
  public:
    Wall(int x, int y);
    Wall(int x, int y, int size_x, int size_y);
    Wall(QPoint w_position);
    Wall(QPoint w_position, QPoint w_size);
    Wall(QPoint w_position, QPoint w_size, Qt::GlobalColor w_color);

    QPoint const get_position();
    QPoint const get_size();
    Qt::GlobalColor const get_color();

  private:
    QPoint position;
    QPoint size = QPoint(50, 50);
    Qt::GlobalColor color = Qt::red;
};

#endif
