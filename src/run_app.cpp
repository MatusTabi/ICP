// #include "src/gui/gui.h"

#include <QApplication>
#include <QMainWindow>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // GUI main_window;
    // main_window.showMaximized();
    
    cout << "Testing print text" << endl;

    return a.exec();
}
