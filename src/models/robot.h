#ifndef ROBOT_H
#define ROBOT_H

#include <QPoint>

enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

enum RotationDirection {
    CLOCKWISE,
    ANTICLOCKWISE
};

class Robot{

    private:
        QPoint position;
        int speed;
        Direction dir = RIGHT;
        RotationDirection rot_dir = CLOCKWISE;
        // angle
    
    public:
        Robot(QPoint r_position);
        Robot(QPoint r_position, Direction r_dir, RotationDirection r_rot_dir);
        Robot(QPoint r_position, int r_speed, Direction r_dir);
        
        void move();
        void rotate();
        QPoint const get_position();
        int const get_speed();
        Direction const get_direction();
};

#endif