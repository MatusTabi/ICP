#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <vector>
#include "../models/robot.h"
#include "../models/wall.h"

class RobotController {
    private:
        std::vector<Robot *> robot_vector;
        std::vector<Wall *> wall_vector;
    
    public:
        RobotController();
        void add_robot(Robot *new_robot);
        void add_wall(Wall *new_wall);
        void add_robot_vector(std::vector<Robot *> new_robot_vector);
        void add_wall_vector(std::vector<Wall *> new_wall_vector);

        bool detect_collision();
        void move_robots(const bool collision);
        void change_collision_distance(int r_collision_distance);
        void change_speed(RobotSpeed r_speed);
        void change_properties(RobotSpeed r_speed, int r_collision_distance);

        std::vector<Robot *> const get_robots();
        std::vector<Wall *> const get_walls();
    
    private:
        std::vector<Wall *> walls_ifo_robot(QPoint r_position, Direction r_dir);
};

#endif
