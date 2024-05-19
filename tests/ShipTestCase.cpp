#include "gtest/gtest.h"

#include "Ships.h"

class ShipTestCase : public ::testing::Test {};

TEST(ShipTestCase, CheckState) {
  Ship s(5, 'a');
  EXPECT_EQ(true, s.check_state());
}