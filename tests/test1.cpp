#include <gtest/gtest.h>
#include "../src/models/robot.h"

#include <vector>
#include <iostream>

class SimpleTest : public testing::Test {
    protected:
        Robot *robot;

        void SetUp() override {
            robot = new Robot(QPoint(100, 100), 2, Direction::LEFT);
        }
};

TEST_F(SimpleTest, initialization_test) {
    EXPECT_EQ(robot->get_direction(), Direction::LEFT);
    EXPECT_EQ(robot->get_position(), QPoint(100, 100));
    EXPECT_EQ(robot->get_speed(), 2);
}

TEST_F(SimpleTest, simple_single_move_test) {
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 100));
}

TEST_F(SimpleTest, move_with_rotation_test) {
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 100));
    robot->rotate();
    EXPECT_EQ(robot->get_direction(), Direction::UP);
    robot->move();
    EXPECT_EQ(robot->get_position(), QPoint(98, 98));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
