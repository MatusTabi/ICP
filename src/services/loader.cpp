#include "loader.hpp"

Loader::Loader() {}

Loader::~Loader() {}

void Loader::load_simulation(std::vector<RobotBase *> &new_robot_vector,
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
    return QFileDialog::getOpenFileName(nullptr, "Open simulation", "./examples/",
                                        "JSON files (*.json)");
}

void Loader::check_file(QFile &file) {
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }
}

void Loader::load_robots(QJsonArray &robots,
                         std::vector<RobotBase *> &new_robot_vector) {
    for (size_t i = 0; i < robots.size(); ++i) {
        QJsonObject robot = robots[i].toObject();
        const Vector2D position{robot["position"].toObject()["x"].toDouble(),
                                robot["position"].toObject()["y"].toDouble()};
        const Vector2D velocity{robot["velocity"].toObject()["x"].toDouble(),
                                robot["velocity"].toObject()["y"].toDouble()};
        const double angle = robot["angle"].toDouble();
        const QColor color = QColor(robot["color"].toObject()["red"].toInt(),
                                    robot["color"].toObject()["green"].toInt(),
                                    robot["color"].toObject()["blue"].toInt());
        const QString type = robot["type"].toString();
        RobotBase *new_robot =
            robot_type[type](position, velocity, angle, color);
        new_robot_vector.push_back(new_robot);
    }
}

void Loader::load_walls(QJsonArray &walls,
                        std::vector<Wall *> &new_wall_vector) {
    for (size_t i = 0; i < walls.size(); ++i) {
        QJsonObject wall = walls[i].toObject();
        Vector2D position{wall["position"].toObject()["x"].toDouble(),
                          wall["position"].toObject()["y"].toDouble()};
        Vector2D size{wall["size"].toObject()["width"].toDouble(),
                      wall["size"].toObject()["height"].toDouble()};
        QColor color = QColor{wall["color"].toObject()["red"].toInt(),
                              wall["color"].toObject()["green"].toInt(),
                              wall["color"].toObject()["blue"].toInt()};
        new_wall_vector.push_back(new Wall{position, size, color});
    }
}

RobotBase *Loader::create_manual_robot(const Vector2D &position,
                                       const Vector2D velocity, int angle,
                                       const QColor &color) {
    return new ManualRobot{position, velocity, angle, color};
}

RobotBase *Loader::create_automatic_robot(const Vector2D &position,
                                          const Vector2D velocity, int angle,
                                          const QColor &color) {
    return new AutomaticRobot{position, velocity, angle, color};
}
