#include "gtest/gtest.h"

#include "Game.h"
#include "Player.h"
#include "Field.h"

class GameTestCase : public ::testing::Test {};

TEST(GameTestCase, AddBotPlayer) {
  std::string name = "";
  Player p(name, Field(), true);
  EXPECT_EQ(p, add_player(1, true));
}