#ifndef MENU_BAR_HPP
#define MENU_BAR_HPP

#include "../controllers/controller.hpp"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>

class MenuBar : public QMenuBar {
    Q_OBJECT

  public:
    MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

  signals:
    void load_simulation();

  private slots:
    void confirm_exit();
    void save();
    void load();

private:
    void set_appearance();
    void set_file_menu();

    Controller *controller_;
};

#endif
