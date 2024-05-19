#include "Ships.h"
#include "gtest/gtest.h"

class ShipTestCase : public ::testing::Test {};

TEST(ShipTestCase, CheckState) {
  Ship s(5, 'a');
  EXPECT_TRUE(s.check_state());
}

TEST(ShipTestCase, GetOrient) {
  Ship s(5, 'a');
  EXPECT_EQ('a', s.check_state());
}