#ifndef TOP_TOOL_BAR_HPP
#define TOP_TOOL_BAR_HPP

#include <QToolBar>
#include "../controllers/controller.hpp"

class TopToolBar : public QToolBar {
    Q_OBJECT
  public:
    TopToolBar(const QString &title, QWidget *parent = nullptr);

  signals:
    void toggle_simulation();
    void add_wall();

  public slots:
    void toggle_action_icon();

  private:
    void setup_actions();
    void setup_connections();

    Controller *controller_;

    QAction *start_stop_action;
    QAction *add_wall_action;
    QAction *add_robot_action;
};

#endif