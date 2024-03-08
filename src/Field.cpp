#include "../include/Field.h"

Field::Field(int sz) : sz(sz), ships_num(0) {
  mt.resize(sz);
  for (int i = 0; i < sz; ++i) {
    mt[i].resize(sz);
  }
}

Field::Field() : Field(kSize) {}

void Field::create_ship(int lth, int x, int y, char orient) {
  Ship new_ship(lth);
  int curr_x = x;
  int curr_y = y;
  for (int i = 0; i < lth; ++i) {
    check_coords(curr_x, curr_y);
    check_surroundings(curr_x, curr_y);
    if (orient == 'n') {
      --curr_x;
    } else if (orient == 'e') {
      ++curr_y;
    } else if (orient == 's') {
      ++curr_x;
    } else {
      --curr_y;
    }
  }
  curr_x = x;
  curr_y = y;
  for (int i = 0; i < lth; ++i) {
    mt[curr_x][curr_y].id = &new_ship;
    mt[curr_x][curr_y].part = i;
    if (orient == 'n') {
      --curr_x;
    } else if (orient == 'e') {
      ++curr_y;
    } else if (orient == 's') {
      ++curr_x;
    } else {
      --curr_y;
    }
  }
  ++ships_num;
}

void Field::check_coords(int x, int y) const {
  if (x < 0 or x >= sz or y < 0 or y >= sz) {
    throw "Out of bounds! Enter again!";
  }
}

void Field::check_shot(int x, int y) {
  if (mt[x][y].was_hit) {
    throw "You've already shot there! Enter the coordinates again!";
  }
}

void Field::hit_field(int x, int y) {
  std::cout << "Executing shot" << std::endl;
  mt[x][y].was_hit = true;
  if (mt[x][y].id == nullptr) {
    std::cout << "Miss!" << std::endl;
  } else {
    (*mt[x][y].id).get_shot(mt[x][y].part);
    if (!(*mt[x][y].id).check_state()) {
      --ships_num;
    }
  }
}

int Field::get_ships() const {
  return ships_num;
}

void Field::check_surroundings(int x, int y) {
  if (mt[x][y].id != nullptr or
      (x != 0 and mt[x - 1][y].id != nullptr) or
      (x != 0 and y != sz - 1 and mt[x - 1][y + 1].id != nullptr) or
      (y != sz - 1 and mt[x][y + 1].id != nullptr) or
      (x != sz - 1 and y != sz - 1 and mt[x + 1][y + 1].id != nullptr) or
      (x != sz - 1 and mt[x + 1][y].id != nullptr) or
      (x != sz - 1 and y != 0 and mt[x + 1][y - 1].id != nullptr) or
      (y != 0 and mt[x][y - 1].id != nullptr) or
      (x != 0 and y != 0 and mt[x - 1][y - 1].id != nullptr)) {
    throw "The new ship touches with the old one! Enter again!";
  }
}