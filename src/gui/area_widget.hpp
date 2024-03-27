#ifndef ROBOT_VIEW_WIDGET_HPP
#define ROBOT_VIEW_WIDGET_HPP

#include "../models/robot.hpp"
#include "../models/wall.hpp"
#include <QWidget>

class AreaWidget : public QWidget {
    Q_OBJECT
  public:
    explicit AreaWidget(QWidget *parent = nullptr);
    void set_models(const std::vector<Robot *> &robots,
                    const std::vector<Wall *> &walls);

  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
    void draw_lines(QPainter &painter, const QPointF &r_position,
                    const int &r_size, const int &r_direction);
    void draw_robots(QPainter &painter);
    void draw_walls(QPainter &painter);

    std::vector<Robot *> robots;
    std::vector<Wall *> walls;
};

#endif
