#include <gtest/gtest.h>
#include "tests/simple_robot_tests.h"
#include "tests/wall_tests.h"
#include "tests/robot_controller_tests.h"
#include "tests/collision_tests.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
