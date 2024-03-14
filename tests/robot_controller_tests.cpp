#include "robot_controller_tests.h"

void RobotControllerTests::SetUp() {
    controller = RobotController();
}

TEST_F(RobotControllerTests, empty_initialization_test) {
    EXPECT_EQ(controller.get_robots().size(), 0);
    EXPECT_EQ(controller.get_walls().size(), 0);
}

TEST_F(RobotControllerTests, one_robot_insert_test) {
    controller.add_robot(new Robot(QPoint(0, 0)));
    EXPECT_EQ(controller.get_robots().size(), 1);
}

TEST_F(RobotControllerTests, one_wall_insert_test) {
    controller.add_wall(new Wall(QPoint(0, 0), QPoint(10, 10)));
    EXPECT_EQ(controller.get_walls().size(), 1);
}

TEST_F(RobotControllerTests, robot_vector_insert_test) {
    std::vector<Robot *> robots = {
        new Robot(QPoint(0, 0)),
        new Robot(QPoint(10, 10))
    };
    controller.add_robot_vector(robots);
    EXPECT_EQ(controller.get_robots().size(), 2);
}

TEST_F(RobotControllerTests, wall_vector_insert_test) {
    std::vector<Wall *> walls = {
        new Wall(QPoint(0, 0)),
        new Wall(QPoint(100, 100))
    };
    controller.add_wall_vector(walls);
    EXPECT_EQ(controller.get_walls().size(), 2);
}

TEST_F(RobotControllerTests, RobotsCollide_Test) {
    std::vector<QPoint> r_positions = {
        QPoint(0, 0),
        QPoint(100, 100),
        QPoint(50, 50)
    };

    std::vector<Robot *> robots = {
        new Robot(r_positions[0]),
        new Robot(r_positions[1]),
        new Robot(r_positions[2])
    };

    controller.add_robot_vector(robots);
    controller.move_robots(true);

    for (int i = 0; i < robots.size(); ++i) {
        QPoint position = robots[i]->get_position();
        const RobotSpeed r_speed = robots[i]->get_speed();

        EXPECT_EQ(position, QPoint(r_positions[i].x(), r_positions[i].y()));
    }
}

TEST_F(RobotControllerTests, moving_robots_test) {
    std::vector<QPoint> r_positions = {
        QPoint(0, 0),
        QPoint(100, 100),
        QPoint(50, 50)
    };

    std::vector<Robot *> robots = {
        new Robot(r_positions[0]),
        new Robot(r_positions[1]),
        new Robot(r_positions[2])
    };

    controller.add_robot_vector(robots);
    controller.move_robots(false);

    for (int i = 0; i < robots.size(); ++i) {
        QPoint position = robots[i]->get_position();
        const RobotSpeed r_speed = robots[i]->get_speed();

        EXPECT_EQ(position, QPoint(r_positions[i].x() + r_speed, r_positions[i].y()));
    }
}
