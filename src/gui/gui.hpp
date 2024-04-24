#ifndef GUI_HPP
#define GUI_HPP

#include "../controllers/controller.hpp"
#include "top_tool_bar.hpp"
#include "area_widget.hpp"
#include "menu_bar.hpp"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GUI;
}
QT_END_NAMESPACE
class GUI : public QMainWindow {
    Q_OBJECT
  public:
    GUI(QWidget *parent = nullptr);
    ~GUI();

  private:
    void setup_ui();
    void setup_connections();

    Controller *controller_;
    AreaWidget *area_widget;
    MenuBar *menu_bar;
    Ui::GUI *ui;
    TopToolBar *top_tool_bar;
};

#endif
