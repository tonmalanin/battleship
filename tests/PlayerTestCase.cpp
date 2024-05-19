#include "Player.h"
#include "gtest/gtest.h"

class PlayerTestCase : public ::testing::Test {
 public:
  static std::string name;
  static Player p;
};

std::string PlayerTestCase::name = "";
Player PlayerTestCase::p(name, Field(), true);

TEST_F(PlayerTestCase, GetName) { EXPECT_EQ("", p.get_name()); }

TEST_F(PlayerTestCase, Lost) { EXPECT_TRUE(p.lost()); }