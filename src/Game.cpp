#include "../include/Game.h"

std::shared_ptr<Player> decide_winner(std::vector<Player> &players) {
  std::vector<std::shared_ptr<Player>> players_left;
  for (auto player : players) {
    if (!player.lost()) {
      players_left.push_back(std::make_shared<Player>(player));
    }
  }
  if (players_left.size() == 1) {
    return players_left[0];
  }
  return nullptr;
}

void make_shot(std::vector<Player> &players, int attacker) {
  int defender = (attacker + 1) % players.size();
  players[attacker].fire(players[defender]);
}

void do_game() {
  start_message();
  Player player1 = add_player(1);
  Player player2 = add_player(2);
  std::vector<Player> players = {player1, player2};
  install_ships(players);
  int turn = 0;
  std::shared_ptr<Player> winner = nullptr;
  while (winner == nullptr) {
    make_shot(players, turn);
    turn = (turn + 1) % players.size();
    winner = decide_winner(players);
  }
  finish_message(winner->get_name());
}

void install_ships(std::vector<Player> &players) {
  for (auto player : players) {
    player.place_ships();
  }
}

Player add_player(int id) {
  Field field;
  std::string name = greetings(id);
  Player player(name, field);
  return player;
}