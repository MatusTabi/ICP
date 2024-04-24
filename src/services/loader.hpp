#ifndef LOADER_HPP
#define LOADER_HPP

#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "../models/wall.hpp"
#include "../models/robot.hpp"

class Loader {
  public:
    Loader();
    ~Loader();

    void load_simulation(std::vector<Robot *> &new_robot_vector,
                         std::vector<Wall *> &new_wall_vector);
  private:
    QString get_filename();
    void check_file(QFile &file);
    void load_robots(QJsonArray &robots, std::vector<Robot *> &new_robot_vector);
    void load_walls(QJsonArray &walls, std::vector<Wall *> &new_wall_vector);
};

#endif
