#include "collision_tests.h"

#include <iostream>

void CollisionTests::SetUp() { controller = RobotController(); }

TEST_F(CollisionTests, NoCollision_Test) {
    controller.add_robot(new Robot{100, 100});
    controller.change_speed(RobotSpeed::SUPERFAST);
    Robot *robot = controller.get_robots()[0];

    EXPECT_EQ(robot->get_speed(), RobotSpeed::SUPERFAST);

    bool collision = controller.detect_collision();
    EXPECT_FALSE(collision);
    controller.move_robots(collision);

    collision = controller.detect_collision();
    EXPECT_FALSE(collision);
    controller.move_robots(collision);

    controller.move_robots(collision);
    collision = controller.detect_collision();
    EXPECT_FALSE(collision);
}

TEST_F(CollisionTests, SimpleCollision_Test) {
    controller.add_robot(new Robot{100, 100});
    controller.change_speed(RobotSpeed::SUPERFAST);
    controller.add_wall(new Wall{190, 0, 60, 200});
    Robot *robot = controller.get_robots()[0];

    bool collision = controller.detect_collision();
    EXPECT_FALSE(collision);
    controller.move_robots(collision);

    collision = controller.detect_collision();
    EXPECT_TRUE(collision);
    controller.move_robots(collision);
    EXPECT_EQ(robot->get_position(), QPoint(150, 100));
}

TEST_F(CollisionTests, CollisionRotate_Test) {
    controller.add_robot(new Robot{5, 5});
    controller.add_wall(new Wall({8, 0, 1, 10}));
    Robot *robot = controller.get_robots()[0];
    robot->set_collision_distance(2);

    bool collision = controller.detect_collision();
    EXPECT_FALSE(collision);
    controller.move_robots(collision);

    collision = controller.detect_collision();
    EXPECT_TRUE(collision);
    controller.move_robots(collision);
    EXPECT_EQ(robot->get_position(), QPoint(7, 5));
    EXPECT_EQ(robot->get_direction(), Direction::DOWN);

    collision = controller.detect_collision();
    EXPECT_FALSE(collision);
    controller.move_robots(collision);
    EXPECT_EQ(robot->get_position(), QPoint(7, 7));
    EXPECT_EQ(robot->get_direction(), Direction::DOWN);
}

TEST_F(CollisionTests, ImmediateCollision_Test) {
    controller.add_robot(new Robot{5, 5});
    controller.change_collision_distance(2);
    controller.add_wall(new Wall{6, 5});
    Robot *robot{controller.get_robots()[0]};

    bool collision{controller.detect_collision()};
    controller.move_robots(collision);

    EXPECT_EQ(robot->get_position(), QPoint(5, 5));
    EXPECT_EQ(robot->get_direction(), Direction::DOWN);
}
