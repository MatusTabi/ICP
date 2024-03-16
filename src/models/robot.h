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

enum RobotSpeed {
    STOP,
    NO_CHANGE,
    SLOW,
    MEDIUM = 5,
    FAST = 10,
    SUPERFAST = 50,
};

class Robot{

    private:
        QPoint position;
        const int size = 30;
        RobotSpeed speed = RobotSpeed::SLOW;
        int collision_distance = 40;
        Direction dir = RIGHT;
        RotationDirection rot_dir = CLOCKWISE;
        // angle
    
    public:
        Robot(int x, int y);
        Robot(QPoint r_position);
        Robot(QPoint r_position, Direction r_dir, RotationDirection r_rot_dir);
        Robot(QPoint r_position, RobotSpeed r_speed);
        Robot(QPoint r_position, RobotSpeed r_speed, Direction r_dir);
        
        void move();
        void rotate();

        QPoint const get_position();
        RobotSpeed const get_speed();
        int const get_collision_distance();
        Direction const get_direction();

        void set_speed(RobotSpeed r_speed);
        void set_collision_distance(int r_coll_length);

};

#endif
