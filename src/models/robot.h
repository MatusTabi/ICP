#ifndef ROBOT_H
#define ROBOT_H

#include <QPoint>

enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Robot{

    private:
        QPoint position;
        int speed;
        Direction dir = RIGHT;
        // rotation direction
        // angle
    
    public:
        Robot(QPoint r_position, int r_speed, Direction r_dir);
        void move();
        void rotate();
        static int sum(int a, int b);


};

#endif