#include "gtest/gtest.h"

#include "IOManager.h"

class IOTestCase : public ::testing::Test {};

TEST(IOTestCase, StartMessage) {
  EXPECT_NO_THROW(start_message());
}