#pragma once

#include <iostream>

#include "Field.h"
#include "Player.h"

int decide_winner(std::vector<Player *> &players);

void make_shot(std::vector<Player *> &players, int attacker);

void do_game();

void install_ships(std::vector<Player *> &players);
