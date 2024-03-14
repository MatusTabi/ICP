#ifndef COLLISION_TESTS_H
#define COLLISION_TESTS_H

#include <gtest/gtest.h>
#include "../src/controllers/robot_controller.h"

class CollisionTests : public testing::Test {
    protected:
        RobotController controller;

        void SetUp() override;
};

#endif
