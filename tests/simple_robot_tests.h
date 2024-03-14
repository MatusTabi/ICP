#ifndef SIMPLE_ROBOT_TESTS_H
#define SIMPLE_ROBOT_TESTS_H

#include <gtest/gtest.h>
#include "../src/models/robot.h"

class SimpleRobotTest : public testing::Test {
    protected:
        Robot *robot;

        void SetUp() override;
};

#endif
