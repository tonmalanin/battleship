#include "Field.h"
#include "gtest/gtest.h"

class FieldTestCase : public ::testing::Test {};

TEST(FieldTestCase, DisplayOwnField) {
  Field f(20);
  EXPECT_NO_THROW(f.display_own_field());
}

TEST(FieldTestCase, DisplayOtherField) {
  Field f(20);
  EXPECT_NO_THROW(f.display_other_field());
}
