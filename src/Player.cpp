#include "../include/Player.h"

Player::Player(int id, const Field &field) : id(id), fld(field) {}

void Player::place_ships() {
  std::cout << "You're player " << id << std::endl;
  for (int i = 0; i < kShipsNumber; ++i) {
    while (true) {
      std::cout << "Enter the coordinates of the bow of a ship of length " << ships_size[i] << ": ";
      std::string coords;
      std::cin >> coords;
      try {
        check_coords(coords);
      } catch (const char *error_message) {
        std::cout << error_message << std::endl;
        continue;
      }
      int x = coords[1] - '0';
      int y = coords[0] - 'A';
      std::string orient;
      while (true) {
        std::cout << "Enter ship orientation (n/e/s/w): ";
        std::cin >> orient;
        if (orient.size() != 1 or (orient[0] != 'n' and orient[0] != 'e' and orient[0] != 's' and orient[0] != 'w')) {
          std::cout << "Incorrect orientation! Enter again!" << std::endl;
          continue;
        }
        break;
      }
      try {
        fld.create_ship(ships_size[i], x, y, orient[0]);
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
    std::cout << "Enter the coordinates: ";
    std::string coords;
    std::cin >> coords;
    try {
      check_coords(coords);
    } catch (const char *error_message) {
      std::cout << error_message << std::endl;
      continue;
    }
    x = coords[1] - '0';
    y = coords[0] - 'A';
    try {
      (*other).fld.check_shot(x, y);
    } catch (const char *error_message) {
      std::cout << error_message << std::endl;
      continue;
    }
    break;
  }
  (*other).fld.hit_field(x, y);
}

int Player::get_id() const {
  return id;
}

bool Player::lost() {
  return fld.get_ships() == 0;
}

void check_coords(std::string& coords){
  if (coords.size() != 2 or coords[0] < 'A' or coords[0] > 'J' or coords[1] < '0' or coords[1] > '9') {
    throw "Incorrect coordinates! Enter again!";
  }
}