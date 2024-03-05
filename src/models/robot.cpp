#include "robot.h"

Robot::Robot(QPoint r_position) : position(r_position) {}

Robot::Robot(QPoint r_position, int r_speed, Direction r_dir) 
    : position(r_position), speed(r_speed), dir(r_dir) {}

Robot::Robot(QPoint r_position, Direction r_dir, RotationDirection r_rot_dir)
    : position(r_position), dir(r_dir), rot_dir(r_rot_dir) {}

void Robot::move() {
    if (dir == Direction::UP) {
        position.setY(position.y() - speed);
    }
    else if (dir == Direction::RIGHT) {
        position.setX(position.x() + speed);
    }
    else if (dir == Direction::DOWN) {
        position.setY(position.y() + speed);
    }
    else {
        position.setX(position.x() - speed);
    }
}

void Robot::rotate() {
    if (rot_dir == RotationDirection::CLOCKWISE) {
        switch(dir) {
            case Direction::UP: dir = Direction::RIGHT; break;
            case Direction::RIGHT: dir = Direction::DOWN; break;
            case Direction::DOWN: dir = Direction::LEFT; break;
            case Direction::LEFT: dir = Direction::UP; break;
        }
    }
    else {
        switch(dir) {
            case Direction::UP: dir = Direction::LEFT; break;
            case Direction::RIGHT: dir = Direction::UP; break;
            case Direction::DOWN: dir = Direction::RIGHT; break;
            case Direction::LEFT: dir = Direction::DOWN; break;
        }
    }
}

QPoint const Robot::get_position() {
    return position;
}

int const Robot::get_speed() {
    return speed;
}

Direction const Robot::get_direction() {
    return dir;
}
