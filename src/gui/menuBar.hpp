/**
 * @file menuBar.hpp
 *
 * @brief This file contains the declaration of the MenuBar class.
 *
 * The class represents the menu bar of the application. The menu bar contains
 * the file and edit menus.
 *
 * @author Matus Tabi
 */

#ifndef MENU_BAR_HPP
#define MENU_BAR_HPP

#include "../controllers/controller.hpp"

#include <QAction>
#include <QCoreApplication>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

class MenuBar : public QMenuBar {
    Q_OBJECT

  public:
    /**
     * @brief Constructor of the MenuBar class.
     */
    MenuBar(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the MenuBar class.
     */
    ~MenuBar();

  signals:

    /**
     * @brief Signal that is emitted when loading the simulation.
     */
    void load_simulation();

    /**
     * @brief Signal that is emitted when redrawing the simulation.
     */
    void redraw();

  private slots:

    /**
     * @brief Confirms the exit of the application.
     */
    void confirm_exit();

    /**
     * @brief Saves the simulation.
     */
    void save();

    /**
     * @brief Loads the simulation.
     */
    void load();

    /**
     * @brief Adds an automatic robot to the simulation.
     */
    void add_auto_robot();

    /**
     * @brief Adds a manual robot to the simulation.
     */
    void add_manual_robot();

    /**
     * @brief Adds a wall to the simulation.
     */
    void add_wall();

  private:
    /**
     * @brief Sets the appearance of the menu bar.
     */
    void set_appearance();

    /**
     * @brief Sets the file menu.
     */
    void set_file_menu();

    /**
     * @brief Sets the edit menu.
     */
    void set_edit_menu();

    /**
     * @brief Controller of the application.
     */
    Controller *controller_;
};

#endif
