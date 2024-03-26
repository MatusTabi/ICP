#ifndef ROBOT_VIEW_WIDGET_H
#define ROBOT_VIEW_WIDGET_H

#include "../models/robot.h"
#include <QWidget>

class RobotViewWidget : public QWidget {
    Q_OBJECT
  public:
    explicit RobotViewWidget(QWidget *parent = nullptr);
    void set_robots(const std::vector<Robot *> &robots);

  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
    void draw_lines(QPainter &painter, const QPointF &r_position,
                    const int &r_size, const int &r_direction);

    std::vector<Robot *> robots;
};

#endif
