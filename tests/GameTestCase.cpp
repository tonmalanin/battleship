#include "gtest/gtest.h"

#include "Game.h"
#include "Player.h"
#include "Field.h"

class GameTestCase : public ::testing::Test {
 public:
  static std::string name;
  static Player p1;
  static Player p2;
  static std::vector<Player> p;
};

std::string GameTestCase::name = "";
Player GameTestCase::p1(name, Field(), true);
Player GameTestCase::p2(name, Field(), true);
std::vector<Player> GameTestCase::p = {p1, p2};

TEST_F(GameTestCase, AddBotPlayer) {
  EXPECT_EQ(p1, add_player(1, true));
}

TEST_F(GameTestCase, InstallShips) {
  EXPECT_NO_THROW(install_ships(p));
}

TEST_F(GameTestCase, MakeShot) {
  EXPECT_NO_THROW(make_shot(p, 0));
}
