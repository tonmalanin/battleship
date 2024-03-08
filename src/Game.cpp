#include "../include/Game.h"

int decide_winner(std::vector<Player *> &players) {
  std::vector<int> players_left;
  for (auto player : players) {
    if (!(*player).lost()) {
      players_left.push_back((*player).get_id());
    }
  }
  if (players_left.size() == 1) {
    return players_left[0];
  }
  return 0;
}

void make_shot(std::vector<Player *> &players, int attacker) {
  int defender = (attacker + 1) % players.size();
  (*players[attacker]).fire(players[defender]);
}

void do_game() {
  std::cout << "Game started" << std::endl;
  Field field1;
  Field field2;
  Player player1(1, field1);
  Player player2(2, field2);
  std::vector<Player *> players = {&player1, &player2};
  install_ships(players);
  int turn = 0;
  int winner = 0;
  while (winner == 0) {
    make_shot(players, turn);
    turn = (turn + 1) % players.size();
    winner = decide_winner(players);
  }
  std::cout << "Player " << winner << " won";
}

void install_ships(std::vector<Player *> &players) {
  for (auto player : players) {
    (*player).place_ships();
  }
}