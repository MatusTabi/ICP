#include "gui/gui.hpp"

#include <QApplication>
#include <QMainWindow>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GUI main_window;
    main_window.showMaximized();
              
    return a.exec();
}
