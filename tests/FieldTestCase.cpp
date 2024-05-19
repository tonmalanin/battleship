#include "gtest/gtest.h"

#include "Field.h"

class FieldTestCase : public ::testing::Test {};

TEST(FieldTestCase, CheckCorrectCoords) {
  Field f(20);
  EXPECT_NO_THROW(f.check_coords(0, 0, true));
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}