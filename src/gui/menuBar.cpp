#include "menuBar.hpp"

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar{parent}, controller_{Controller::get_instance()} {
    set_appearance();

    set_file_menu();
    set_edit_menu();

    addMenu(tr("View"));
    addMenu(tr("Help"));
}

MenuBar::~MenuBar() {}

void MenuBar::confirm_exit() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Exit simulation");
    msgBox.setInformativeText("Are you sure you want to exit?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    QMessageBox::StandardButton reply =
        static_cast<QMessageBox::StandardButton>(msgBox.exec());
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit();
    }
}

void MenuBar::save() { controller_->save_simulation(); }

void MenuBar::load() {
    controller_->load_simulation();
    emit load_simulation();
}

void MenuBar::set_file_menu() {
    QMenu *file_menu = addMenu(tr("File"));
    QAction *load_action = file_menu->addAction(tr("Load simulation"));
    QAction *save_action = file_menu->addAction(tr("Save simulation"));
    QAction *exit_action = file_menu->addAction(tr("Exit"));

    connect(load_action, &QAction::triggered, this, &MenuBar::load);
    connect(save_action, &QAction::triggered, this, &MenuBar::save);
    connect(exit_action, &QAction::triggered, this, &MenuBar::confirm_exit);
}

void MenuBar::set_edit_menu() {
    QMenu *edit_menu = addMenu(tr("Edit"));
    QAction *add_autorobot_action =
        edit_menu->addAction(tr("Add automatic robot"));
    add_autorobot_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    add_autorobot_action->setToolTip(tr("Ctrl+R"));

    QAction *add_manualrobot_action =
        edit_menu->addAction(tr("Add manual robot"));
    add_manualrobot_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));
    add_manualrobot_action->setToolTip(tr("Ctrl+M"));

    QAction *add_wall_action = edit_menu->addAction(tr("Add wall"));
    add_wall_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    add_wall_action->setToolTip(tr("Ctrl+W"));

    connect(add_autorobot_action, &QAction::triggered, this,
            &MenuBar::add_auto_robot);
    connect(add_manualrobot_action, &QAction::triggered, this,
            &MenuBar::add_manual_robot);
    connect(add_wall_action, &QAction::triggered, this, &MenuBar::add_wall);
}

void MenuBar::add_auto_robot() {
    controller_->add_robot(new AutomaticRobot{AutomaticRobot::DefaultPosition,
                                              AutomaticRobot::DefaultVelocity});
    emit redraw();
}

void MenuBar::add_manual_robot() {
    controller_->add_robot(new ManualRobot{ManualRobot::DefaultPosition,
                                          ManualRobot::DefaultVelocity});
    emit redraw();
}

void MenuBar::add_wall() {
    controller_->add_wall(new Wall{Wall::DefaultPosition, Wall::DefaultSize});
    emit redraw();
}

void MenuBar::set_appearance() {
    setStyleSheet(
        "QMenuBar { font-size: 20px; }"
        "QMenuBar { color: #ffffff; }"
        "QMenu { background-color: #2d2d2d; color: #ffffff; margin: 2px; }"
        "QMenu::item { padding: 2px 25px 2px 20px; }"
        "QMenu::item { font-size: 20px; }"
        "QMenu::item:selected { background-color: #3d8ec9; }");
}
