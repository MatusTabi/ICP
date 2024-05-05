/**
 * @file gui.hpp
 * 
 * @brief This file contains the declaration of the GUI class.
 * 
 * The file contains the declaration of the GUI class. The class represents the
 * main window of the application.
 * 
 * @author Matus Tabi
*/

#ifndef GUI_HPP
#define GUI_HPP

#include "../controllers/controller.hpp"
#include "areaWidget.hpp"
#include "menuBar.hpp"
#include "sideBar.hpp"
#include <QMainWindow>

class GUI : public QMainWindow {
    Q_OBJECT
  public:

    /**
     * @brief Constructor of the GUI class.
    */
    GUI(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the GUI class.
    */
    ~GUI();

  private:

    /**
     * @brief Sets up the user interface.
    */
    void setup_ui();

    /**
     * @brief Sets up the connections between the widgets.
    */
    void setup_connections();

    /**
     * @brief The controller of the application.
    */
    Controller *controller_;

    /**
     * @brief The widget that displays the area.
    */
    AreaWidget *area_widget;

    /**
     * @brief The menu bar of the application.
    */
    MenuBar *menu_bar;

    /**
     * @brief The side bar of the application.
    */
    SideBar *side_bar;
};

#endif
