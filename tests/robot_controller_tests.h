#ifndef ROBOT_CONTROLLER_TESTS_H
#define ROBOT_CONTROLLER_TESTS_H

#include "../src/controllers/robot_controller.h"
#include <gtest/gtest.h>

class RobotControllerTests : public testing::Test {
  protected:
    RobotController controller_;

    void SetUp() override;
};

#endif
