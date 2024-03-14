#include "simple_robot_tests.h"

void SimpleRobotTest::SetUp() {
    robot = new Robot(QPoint(100, 100), RobotSpeed::SLOW, Direction::LEFT);
}

TEST_F(SimpleRobotTest, initialization_test) {
    EXPECT_EQ(robot->get_direction(), Direction::LEFT);
    EXPECT_EQ(robot->get_position(), QPoint(100, 100));
    EXPECT_EQ(robot->get_speed(), RobotSpeed::SLOW);
}

TEST_F(SimpleRobotTest, simple_single_move_test) {
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 100));
}

TEST_F(SimpleRobotTest, move_with_rotation_test) {
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 100));
    robot->rotate();
    EXPECT_EQ(robot->get_direction(), Direction::UP);
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 98));
}
