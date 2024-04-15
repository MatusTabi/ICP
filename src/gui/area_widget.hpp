#ifndef ROBOT_VIEW_WIDGET_HPP
#define ROBOT_VIEW_WIDGET_HPP

#include "../models/robot.hpp"
#include "../models/wall.hpp"
#include "../utilities/vector2d.hpp"
#include "../controllers/controller.hpp"
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
class AreaWidget : public QWidget {
    Q_OBJECT
  public:
    AreaWidget(QWidget *parent = nullptr);
    void set_models(const std::vector<Robot *> &robots,
                    const std::vector<Wall *> &walls);

  signals:
    void pause();

  public slots:
    void toggle_timer();
    void add_wall();

  protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

  private slots:
    void update_position();

  private:
    void setup_timer();
    // void setup_connections();

    void draw_robots(QPainter &painter);
    void draw_lines(QPainter &painter, const QPointF &r_position,
                    const int &r_size, const int &r_direction);
    void draw_walls(QPainter &painter);
    void draw_border(QPainter &painter);

    const int kTileSize{64};
    const int kInterval{17};
    std::vector<Robot *> robots;
    std::vector<Wall *> walls;
    QTimer *timer;
    Controller *controller_;

    Wall *selected_wall;
};

#endif
