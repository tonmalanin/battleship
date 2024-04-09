#include "../include/Player.h"

Player::Player(std::string &name, const Field &field) : name(name), fld(field) {}

void Player::place_ships() {
  notify(Notice::Place, name);
  for (int i = 0; i < kShipsNumber; ++i) {
    while (true) {
      fld.display_own_field();
      std::string coords;
      try {
        coords = get_coords(ships_size[i]);
      } catch (...) {
        continue;
      }
      int x = coords[1] - '0';
      int y = coords[0] - 'A';
      std::string orient = get_orient();
      try {
        fld.create_ship(ships_size[i], x, y, orient[0]);
      } catch (...) {
        continue;
      }
      break;
    }
  }
}

void Player::fire(Player &other) const {
  notify(Notice::Move, name);
  int x;
  int y;
  while (true) {
    other.fld.display_other_field();
    std::string coords;
    try {
      coords = get_coords(0);
    } catch (...) {
      continue;
    }
    x = coords[1] - '0';
    y = coords[0] - 'A';
    try {
      other.fld.check_shot(x, y);
    } catch (...) {
      continue;
    }
    break;
  }
  other.fld.hit_field(x, y);
}

std::string &Player::get_name() {
  return name;
}

bool Player::lost() {
  return fld.get_ships_num() == 0;
}
