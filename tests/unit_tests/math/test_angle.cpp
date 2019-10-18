#include "gtest/gtest.h"
#include "../../../src/headers/math/util.h"

TEST(Angle, AngleDifference) {
    double a = 360;
    double b = 180;
    EXPECT_EQ(MUtil::angleBetween(a,b), 180);
}