#include "../include/Player.h"

Player::Player(std::string &name, const Field &field, bool is_bot) : name(name), fld(field), is_bot(is_bot) {}

void Player::place_ships() {
  bool is_random = is_bot;
  if (!is_bot) {
    notify(Notice::Place, name);
    settings_change_report(Settings::Random, is_random);
  }
  for (int i = 0; i < kShipsNumber; ++i) {
    while (true) {
      int x, y;
      std::string orient;
      if (!is_random) {
        fld.display_own_field();
        std::string coords;
        try {
          coords = get_coords(ships_size[i]);
        } catch (...) {
          continue;
        }
        x = coords[1] - '0';
        y = coords[0] - 'A';
        orient = get_orient();
      } else {
        std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
        x = rnd();
        y = rnd();
        x = abs(x);
        y = abs(y);
        std::vector<std::string> choices = {"n", "e", "s", "w"};
        orient = choices[rnd() % 4];
      }
      try {
        fld.create_ship(ships_size[i], x, y, orient[0], is_random);
      } catch (...) {
        continue;
      }
      break;
    }
  }
  if (is_random and !is_bot) {
    fld.display_own_field();
    sleep(2);
  }
}

void Player::fire(Player &other) const {
  if (!is_bot) {
    notify(Notice::Move, name);
  } else {
    notify(Notice::EnemyMove, "");
  }
  int x;
  int y;
  while (true) {
    if (!is_bot) {
      fld.display_own_field();
      other.fld.display_other_field();
      std::string coords;
      try {
        coords = get_coords(0);
      } catch (...) {
        continue;
      }
      x = coords[1] - '0';
      y = coords[0] - 'A';
    } else {
      std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
      x = rnd();
      y = rnd();
      x = abs(x);
      y = abs(y);
    }
    try {
      other.fld.check_shot(x, y, is_bot);
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
