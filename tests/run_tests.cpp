#include <gtest/gtest.h>
#include "simple_robot_tests.h"
#include "wall_tests.h"
#include "robot_controller_tests.h"
#include "collision_tests.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
