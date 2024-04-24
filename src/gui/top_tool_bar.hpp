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
    void redraw();

  public slots:
    void toggle_action_icon();

  private slots:
    void add_wall();
    void add_robot();

  private:
    void setup_actions();
    void setup_connections();

    Controller *controller_;

    QAction *start_stop_;
    QAction *wall_;
    QAction *robot_;
    QAction *manual_robot_;
};

#endif