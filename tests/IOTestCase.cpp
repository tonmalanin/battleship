#include "IOManager.h"
#include "gtest/gtest.h"

class IOTestCase : public ::testing::Test {};

TEST(IOTestCase, StartMessage) { EXPECT_NO_THROW(start_message()); }

TEST(IOTestCase, FinishMessage) {
  std::string name = "";
  EXPECT_NO_THROW(finish_message(name));
}

TEST(IOTestCase, PlaceNotice) {
  std::string name = "";
  PlaceNotice note;
  EXPECT_NO_THROW(notify(&note, name));
}

TEST(IOTestCase, MoveNotice) {
  std::string name = "";
  MoveNotice note;
  EXPECT_NO_THROW(notify(&note, name));
}