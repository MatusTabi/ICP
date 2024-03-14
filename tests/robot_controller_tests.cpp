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
