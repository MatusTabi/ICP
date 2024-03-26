#ifndef SIMPLE_ROBOT_TESTS_H
#define SIMPLE_ROBOT_TESTS_H

#include "../src/models/robot.h"
#include <gtest/gtest.h>

class SimpleRobotTest : public testing::Test {
  protected:
    Robot *robot;

    void SetUp() override;
    void TearDown() override;
};

#endif
