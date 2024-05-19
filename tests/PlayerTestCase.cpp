#include "gtest/gtest.h"

#include "Player.h"

class PlayerTestCase : public ::testing::Test {};

TEST(PlayerTestCase, GetName) {
  std::string name = "";
  Player p(name, Field(), true);
  EXPECT_EQ("", p.get_name());
}