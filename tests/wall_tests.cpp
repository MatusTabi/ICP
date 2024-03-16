#include "wall_tests.h"

void WallTest::SetUp() {
    wall = new Wall(QPoint(200, 200), QPoint(40, 80));
    wall_color = new Wall(QPoint(0, 0), QPoint(20, 20), Qt::GlobalColor::blue);
}

TEST_F(WallTest, Initialization_Test) {
    EXPECT_EQ(wall->get_position(), QPoint(200, 200));
    EXPECT_EQ(wall->get_size(), QPoint(40, 80));
    EXPECT_EQ(wall->get_color(), Qt::GlobalColor::red);
}

TEST_F(WallTest, ColorInitialization_Test) {
    EXPECT_EQ(wall_color->get_position(), QPoint(0, 0));
    EXPECT_EQ(wall_color->get_size(), QPoint(20, 20));
    EXPECT_EQ(wall_color->get_color(), Qt::GlobalColor::blue);
}
