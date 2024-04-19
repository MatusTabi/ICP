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
    ~AreaWidget();
    void set_models(const std::vector<Robot *> &robots,
                    const std::vector<Wall *> &walls);

  signals:
    void pause();

  public slots:
    void toggle_timer();
    void redraw();

  protected:
    void paintEvent(QPaintEvent *event) override;
    void showEvent(QShowEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

  private slots:
    void update_position();

  private:
    void setup_timer();
    void reset_robots();

    void draw_robots(QPainter &painter);
    void draw_walls(QPainter &painter);
    void draw_border(QPainter &painter);

    const int kInterval{17};
    std::vector<Robot *> robots;
    std::vector<Wall *> walls;
    QTimer *timer;
    Controller *controller_;

    bool rotation_mode{false};

    Wall *selected_wall = nullptr;
    Robot *selected_robot = nullptr;
};

#endif
