#include "robot_controller_tests.h"

void RobotControllerTests::SetUp() { controller_ = RobotController(); }

TEST_F(RobotControllerTests, EmptyInitialization_Test) {
    EXPECT_EQ(controller_.get_robots().size(), 0);
    EXPECT_EQ(controller_.get_walls().size(), 0);
}

TEST_F(RobotControllerTests, InsertOneRobot_Test) {
    controller_.add_robot(new Robot(QPoint(0, 0)));
    EXPECT_EQ(controller_.get_robots().size(), 1);
}

TEST_F(RobotControllerTests, InsertOneWall_Test) {
    controller_.add_wall(new Wall(QPoint(0, 0), QPoint(10, 10)));
    EXPECT_EQ(controller_.get_walls().size(), 1);
}

TEST_F(RobotControllerTests, InsertRobotVector_Test) {
    std::vector<Robot *> robots = {new Robot(QPoint(0, 0)),
                                   new Robot(QPoint(10, 10))};
    controller_.add_robot_vector(robots);
    EXPECT_EQ(controller_.get_robots().size(), 2);
}

TEST_F(RobotControllerTests, InsertWallVector_Test) {
    std::vector<Wall *> walls = {new Wall(QPoint(0, 0)),
                                 new Wall(QPoint(100, 100))};
    controller_.add_wall_vector(walls);
    EXPECT_EQ(controller_.get_walls().size(), 2);
}

TEST_F(RobotControllerTests, RobotsCollide_Test) {
    std::vector<QPoint> r_positions{QPoint(0, 0), QPoint(100, 100),
                                    QPoint(50, 50)};

    std::vector<Robot *> robots{new Robot(r_positions[0]),
                                new Robot(r_positions[1]),
                                new Robot(r_positions[2])};

    controller_.add_robot_vector(robots);
    controller_.move_robots(true);

    for (std::size_t i = 0; i < robots.size(); ++i) {
        const QPoint position = robots[i]->get_position();
        const RobotSpeed r_speed = robots[i]->get_speed();

        EXPECT_EQ(position, QPoint(r_positions[i].x(), r_positions[i].y()));
    }
}

TEST_F(RobotControllerTests, MovingRobots_Test) {
    std::vector<QPoint> r_positions{QPoint(0, 0), QPoint(100, 100),
                                    QPoint(50, 50)};

    std::vector<Robot *> robots{new Robot(r_positions[0]),
                                new Robot(r_positions[1]),
                                new Robot(r_positions[2])};

    controller_.add_robot_vector(robots);
    controller_.move_robots(false);

    for (std::size_t i = 0; i < robots.size(); ++i) {
        const QPoint position = robots[i]->get_position();
        const RobotSpeed r_speed = robots[i]->get_speed();

        EXPECT_EQ(position,
                  QPoint(r_positions[i].x() + r_speed, r_positions[i].y()));
    }
}
