#ifndef ROBOT_CONTROLLER_TESTS_H
#define ROBOT_CONTROLLER_TESTS_H

#include <gtest/gtest.h>
#include "../src/controllers/robot_controller.h"

class RobotControllerTests : public testing::Test {
    protected:
        RobotController controller;

        void SetUp() override;
};

#endif
