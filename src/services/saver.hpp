/**
 * @file saver.hpp
 * @brief Definition of the Saver class.
 * 
 * The Saver class is used to save the current simulation state to a json file into saved/ folder.
 * The class provides a method to save the simulation state, which includes the robots and walls.
 * 
 * @author Matus Tabi
*/

#ifndef SAVER_HPP
#define SAVER_HPP

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

#include "../models/automaticRobot.hpp"
#include "../models/wall.hpp"

class Saver {
  public:

    /**
     * @brief Default constructor.
    */
    Saver();

    /**
     * @brief Default destructor.
    */
    ~Saver();
    
    /**
     * @brief Saves the current simulation state to a json file.
     * 
     * @param robots The vector of robots to save.
     * @param walls The vector of walls to save.
    */
    void save_simulation(std::vector<RobotBase *> robots, std::vector<Wall *> walls);
  
  private:

    /**
     * @brief Saves the robots to a json array.
     * 
     * @param robots_json The json array to save the robots to.
     * @param robots The vector of robots to save.
    */
    void save_robots(QJsonArray &robots_json, std::vector<RobotBase *> robots);

    /**
     * @brief Saves the walls to a json array.
     * 
     * @param walls_json The json array to save the walls to.
     * @param walls The vector of walls to save.
    */
    void save_walls(QJsonArray &walls_json, std::vector<Wall *> walls);

    /**
     * @brief Gets the filename from the user.
     * 
     * @return The filename.
    */
    QString get_filename();

    /**
     * @brief Checks the extension of the filename.
     * 
     * @param filename The filename to check.
    */
    void check_extension(QString &filename);

    /**
     * @brief Checks the file.
     * 
     * @param file The file to check.
    */
    void check_file(QFile &file);
};

#endif
