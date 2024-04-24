#ifndef SAVER_HPP
#define SAVER_HPP

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

#include "../models/robot.hpp"
#include "../models/wall.hpp"

class Saver {
  public:
    Saver();
    ~Saver();
    void save_simulation(std::vector<Robot *> robots, std::vector<Wall *> walls);
  
  private:
    void save_robots(QJsonArray &robots_json, std::vector<Robot *> robots);
    void save_walls(QJsonArray &walls_json, std::vector<Wall *> walls);
    QString get_filename();
    void check_extension(QString &filename);
    void check_file(QFile &file);
};

#endif
