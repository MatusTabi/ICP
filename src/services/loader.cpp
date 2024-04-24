#include "loader.hpp"

Loader::Loader() {}

Loader::~Loader() {}

void Loader::load_simulation(std::vector<Robot *> &new_robot_vector,
                             std::vector<Wall *> &new_wall_vector) {

    QFile file{get_filename()};
    check_file(file);

    QByteArray data = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(data);

    QJsonObject simulation = document.object();
    QJsonArray robots = simulation["robots"].toArray();
    QJsonArray walls = simulation["walls"].toArray();

    load_robots(robots, new_robot_vector);
    load_walls(walls, new_wall_vector);
}

QString Loader::get_filename() {
    return QFileDialog::getOpenFileName(nullptr, "Open simulation", "./saved/",
                                        "JSON files (*.json)");
}

void Loader::check_file(QFile &file) {
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }
}

void Loader::load_robots(QJsonArray &robots,
                         std::vector<Robot *> &new_robot_vector) {
    for (size_t i = 0; i < robots.size(); ++i) {
        QJsonObject robot = robots[i].toObject();
        Vector2D position{robot["position"].toObject()["x"].toDouble(),
                          robot["position"].toObject()["y"].toDouble()};
        Vector2D velocity{robot["velocity"].toObject()["x"].toDouble(),
                          robot["velocity"].toObject()["y"].toDouble()};
        double angle = robot["angle"].toDouble();
        QColor color = QColor(robot["color"].toString());
        new_robot_vector.push_back(new Robot(position, velocity));
    }
}

void Loader::load_walls(QJsonArray &walls,
                        std::vector<Wall *> &new_wall_vector) {
    for (size_t i = 0; i < walls.size(); ++i) {
        QJsonObject wall = walls[i].toObject();
        Vector2D position{wall["x"].toDouble(), wall["y"].toDouble()};
        Vector2D size{wall["width"].toDouble(), wall["height"].toDouble()};
        new_wall_vector.push_back(new Wall(position, size));
    }
}
