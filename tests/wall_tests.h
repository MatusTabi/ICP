#ifndef WALL_TESTS_H
#define WALL_TESTS_H

#include "../src/models/wall.h"
#include <gtest/gtest.h>

class WallTest : public testing::Test {
  protected:
    Wall *wall;
    Wall *wall_color;

    void SetUp() override;
};

#endif
