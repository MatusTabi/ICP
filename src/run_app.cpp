#include "gui/gui.h"

#include <QApplication>
#include <QMainWindow>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GUI main_window;
    main_window.showMaximized();

    std::cout << "Testing print text"
              << "\n";

    return a.exec();
}
