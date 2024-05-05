#include "saver.hpp"

Saver::Saver() {}

Saver::~Saver() {}

void Saver::save_simulation(std::vector<RobotBase *> robots,
                            std::vector<Wall *> walls) {

    QJsonArray robots_json;
    QJsonArray walls_json;

    save_robots(robots_json, robots);
    save_walls(walls_json, walls);

    QJsonObject simulation;
    simulation["robots"] = robots_json;
    simulation["walls"] = walls_json;

    QJsonDocument document{simulation};

    QString filename = get_filename();
    check_extension(filename);

    if (filename.isEmpty()) {
        return;
    }

    QFile file(filename);
    check_file(file);
    file.write(document.toJson());
}

QString Saver::get_filename() {
    return QFileDialog::getSaveFileName(nullptr, "Save Simulation", "./examples/",
                                        "JSON Files (*.json)");
}

void Saver::check_extension(QString &filename) {
    QFileInfo fileInfo(filename);
    if (fileInfo.suffix().isEmpty()) {
        filename += ".json";
    }
}

void Saver::check_file(QFile &file) {
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(nullptr, "Unable to open file",
                                 file.errorString());
        return;
    }
}

void Saver::save_robots(QJsonArray &robots_json,
                        std::vector<RobotBase *> robots) {
    for (RobotBase *robot : robots) {
        QJsonObject robot_obj;

        robot_obj["type"] = robot->type();

        QJsonObject position;
        position["x"] = robot->get_position().x_;
        position["y"] = robot->get_position().y_;
        robot_obj["position"] = position;

        QJsonObject velocity;
        velocity["x"] = robot->velocity().x_;
        velocity["y"] = robot->velocity().y_;
        robot_obj["velocity"] = velocity;

        robot_obj["angle"] = robot->rotation_angle();

        QJsonObject color;
        color["red"] = robot->color().red();
        color["green"] = robot->color().green();
        color["blue"] = robot->color().blue();
        robot_obj["color"] = color;

        robots_json.append(robot_obj);
    }
}

void Saver::save_walls(QJsonArray &walls_json, std::vector<Wall *> walls) {
    for (Wall *wall : walls) {
        QJsonObject wall_obj;

        QJsonObject position;
        position["x"] = wall->position().x_;
        position["y"] = wall->position().y_;
        wall_obj["position"] = position;

        QJsonObject size;
        size["width"] = wall->size().x_;
        size["height"] = wall->size().y_;
        wall_obj["size"] = size;

        QJsonObject color;
        color["red"] = wall->color().red();
        color["green"] = wall->color().green();
        color["blue"] = wall->color().blue();
        wall_obj["color"] = color;

        walls_json.append(wall_obj);
    }
}
