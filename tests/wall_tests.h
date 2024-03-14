#ifndef WALL_TESTS_H
#define WALL_TESTS_H

#include <gtest/gtest.h>
#include "../src/models/wall.h"

class WallTest : public testing::Test {
    protected:
        Wall *wall;
        Wall *wall_color;

        void SetUp() override;
};

#endif
