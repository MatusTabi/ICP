#include "robot.h"

Robot::Robot(int x, int y) : position{x, y} {}

Robot::Robot(QPoint r_position) : position{r_position} {}

Robot::Robot(QPoint r_position, RobotSpeed r_speed, Direction r_dir) 
    : position{r_position}, speed{r_speed}, dir{r_dir} {}

Robot::Robot(QPoint r_position, RobotSpeed r_speed) : position{r_position}, speed{r_speed} {}

Robot::Robot(QPoint r_position, Direction r_dir, RotationDirection r_rot_dir)
    : position{r_position}, dir{r_dir}, rot_dir{r_rot_dir} {}

void Robot::move() {
    switch(dir) {
        case Direction::UP: 
            position.setY(position.y() - speed); 
            break;
        case Direction::RIGHT: 
            position.setX(position.x() + speed); 
            break;
        case Direction::DOWN: 
            position.setY(position.y() + speed); 
            break;
        case Direction::LEFT: 
            position.setX(position.x() - speed); 
            break;
    }
}

void Robot::rotate() {
    if (rot_dir == RotationDirection::CLOCKWISE) {
        dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
    }
    else {
        dir = static_cast<Direction>((static_cast<int>(dir) + 3) % 4);
    }
}

QPoint const Robot::get_position() {
    return position;
}

RobotSpeed const Robot::get_speed() {
    return speed;
}

int const Robot::get_collision_distance() {
    return collision_distance;
}

Direction const Robot::get_direction() {
    return dir;
}

void Robot::set_speed(RobotSpeed r_speed) {
    speed = r_speed;
}

void Robot::set_collision_distance(int r_coll_length) {
    collision_distance = r_coll_length;
}
