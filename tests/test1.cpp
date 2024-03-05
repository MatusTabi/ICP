#include <gtest/gtest.h>
#include "../src/models/robot.h"

TEST(AddTest, AddsTwoIntegers) {
    EXPECT_EQ(Robot::sum(3, 9), 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}