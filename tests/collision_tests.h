#ifndef COLLISION_TESTS_H
#define COLLISION_TESTS_H

#include "../src/controllers/robot_controller.h"
#include <gtest/gtest.h>

class CollisionTests : public testing::Test {
  protected:
    RobotController controller;

    void SetUp() override;
    // void TearDown() override;
};

#endif
