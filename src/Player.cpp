#include "../include/Player.h"

Player::Player(int id, const Field &field) : id(id), fld(field) {}

void Player::place_ships() {
  std::cout << "You're player " << id << std::endl;
  for (int i = 0; i < kShipsNumber; ++i) {
    while (true) {
      std::cout << "Enter the coordinates of the bow of a ship of length " << ships_size[i] << " (row column): ";
      int x;
      int y;
      std::cin >> x >> y;
      char orient;
      while (true) {
        std::cout << "Enter ship orientation (n/e/s/w): ";
        std::cin >> orient;
        if (orient != 'n' and orient != 'e' and orient != 's' and orient != 'w') {
          std::cout << "Incorrect orientation! Enter again!" << std::endl;
          continue;
        }
        break;
      }
      try {
        fld.create_ship(ships_size[i], x - 1, y - 1, orient);
      } catch (const char *error_message) {
        std::cout << error_message << std::endl;
        continue;
      }
      break;
    }
  }
}

void Player::fire(Player *other) const {
  std::cout << "You're player " << id << std::endl;
  int x;
  int y;
  while (true) {
    std::cout << "Enter the coordinates (row column): ";
    std::cin >> x >> y;
    try {
      (*other).fld.check_shot(x - 1, y - 1);
    } catch (const char *error_message) {
      std::cout << error_message << std::endl;
      continue;
    }
    break;
  }
  (*other).fld.hit_field(x - 1, y - 1);
}

int Player::get_id() const {
  return id;
}

bool Player::lost() {
  return fld.get_ships() == 0;
}