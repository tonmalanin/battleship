#pragma once

#include <iostream>
#include <memory>
#include <unistd.h>

#include "Field.h"
#include "Player.h"

std::shared_ptr<Player> decide_winner(std::vector<Player> &players);

void make_shot(std::vector<Player> &players, int attacker);

void do_game();

void install_ships(std::vector<Player> &players);

Player add_player(int id);
