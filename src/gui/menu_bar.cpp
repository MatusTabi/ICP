#include "menu_bar.hpp"

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar{parent}, controller_{Controller::get_instance()} {
    set_appearance();

    set_file_menu();

    addMenu(tr("Edit"));
    addMenu(tr("View"));
    addMenu(tr("Help"));
}

MenuBar::~MenuBar() {}

void MenuBar::confirm_exit() {
    QMessageBox::StandardButton reply;
    reply =
        QMessageBox::question(this, "Exit", "Are you sure you want to exit?",
                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit();
    }
}

void MenuBar::save() { controller_->save_simulation(); }

void MenuBar::load() { controller_->load_simulation();
    emit load_simulation();
 }

void MenuBar::set_file_menu() {
    QMenu *file_menu = addMenu(tr("File"));
    file_menu->addAction(tr("New simulation"));
    QAction *load_action = file_menu->addAction(tr("Load simulation"));
    QAction *save_action = file_menu->addAction(tr("Save simulation"));
    QAction *exit_action = file_menu->addAction(tr("Exit"));

    connect(load_action, &QAction::triggered, this, &MenuBar::load);
    connect(save_action, &QAction::triggered, this, &MenuBar::save);
    connect(exit_action, &QAction::triggered, this, &MenuBar::confirm_exit);
}

void MenuBar::set_appearance() {
    setStyleSheet(
        "QMenuBar { font-size: 20px; }"
        "QMenu { background-color: #2d2d2d; color: #ffffff; margin: 2px; }"
        "QMenu::item { padding: 2px 25px 2px 20px; }"
        "QMenu::item { font-size: 20px; }"
        "QMenu::item:selected { background-color: #3d8ec9; }");
}
