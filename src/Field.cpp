#include "../include/Field.h"

Field::Field(int sz) : sz(sz), ships_num(0) {
  mt.resize(sz);
  for (int i = 0; i < sz; ++i) {
    mt[i].resize(sz);
  }
}

Field::Field() : Field(kSize) {}

void Field::create_ship(int lth, int x, int y, char orient, bool is_bot) {
  if (is_bot) {
    x %= sz;
    y %= sz;
  }
  int curr_x = x;
  int curr_y = y;
  for (int i = 0; i < lth; ++i) {
    check_coords(curr_x, curr_y, is_bot);
    check_surroundings(curr_x, curr_y, is_bot);
    if (orient == 'n') {
      ++curr_x;
    } else if (orient == 'e') {
      --curr_y;
    } else if (orient == 's') {
      --curr_x;
    } else {
      ++curr_y;
    }
  }
  Ship new_ship(lth, orient);
  ships.push_back(new_ship);
  curr_x = x;
  curr_y = y;
  for (int i = 0; i < lth; ++i) {
    mt[curr_x][curr_y].id = ships_num;
    mt[curr_x][curr_y].part = i;
    if (orient == 'n') {
      ++curr_x;
    } else if (orient == 'e') {
      --curr_y;
    } else if (orient == 's') {
      --curr_x;
    } else {
      ++curr_y;
    }
  }
  ++ships_num;
}

void Field::check_coords(int x, int y, bool is_bot) const {
  if (x < 0 or x >= sz or y < 0 or y >= sz) {
    if (!is_bot) {
      report_error(Error::Coords);
    }
    throw std::exception();
  }
}

void Field::check_shot(int x, int y) {
  if (mt[x][y].was_hit) {
    report_error(Error::Shot);
    throw std::exception();
  }
}

void Field::hit_field(int x, int y) {
  mt[x][y].was_hit = true;
  if (mt[x][y].id == -1) {
    shot_results_report(-1);
  } else {
    ships[mt[x][y].id].get_shot(mt[x][y].part);
    if (!ships[mt[x][y].id].check_state()) {
      --ships_num;
      shot_results_report(0);
    } else {
      shot_results_report(1);
    }
  }
}

int Field::get_ships_num() const {
  return ships_num;
}

void Field::check_surroundings(int x, int y, bool is_bot) {
  if (mt[x][y].id != -1 or (x != 0 and mt[x - 1][y].id != -1) or (x != 0 and y != sz - 1 and mt[x - 1][y + 1].id != -1) or (y != sz - 1 and mt[x][y + 1].id != -1) or (x != sz - 1 and y != sz - 1 and mt[x + 1][y + 1].id != -1) or (x != sz - 1 and mt[x + 1][y].id != -1) or (x != sz - 1 and y != 0 and mt[x + 1][y - 1].id != -1) or (y != 0 and mt[x][y - 1].id != -1) or (x != 0 and y != 0 and mt[x - 1][y - 1].id != -1)) {
    if (!is_bot) {
      report_error(Error::Surroundings);
    }
    throw std::exception();
  }
}

bool Field::check_sunken_around(int x, int y) {
  return (x != 0 and mt[x - 1][y].id != -1 and !ships[mt[x - 1][y].id].check_state()) or
      (x != 0 and y != sz - 1 and mt[x - 1][y + 1].id != -1 and !ships[mt[x - 1][y + 1].id].check_state()) or
      (y != sz - 1 and mt[x][y + 1].id != -1 and !ships[mt[x][y + 1].id].check_state()) or
      (x != sz - 1 and y != sz - 1 and mt[x + 1][y + 1].id != -1 and !ships[mt[x + 1][y + 1].id].check_state()) or
      (x != sz - 1 and mt[x + 1][y].id != -1 and !ships[mt[x + 1][y].id].check_state()) or
      (x != sz - 1 and y != 0 and mt[x + 1][y - 1].id != -1 and !ships[mt[x + 1][y - 1].id].check_state()) or
      (y != 0 and mt[x][y - 1].id != -1 and !ships[mt[x][y - 1].id].check_state()) or
      (x != 0 and y != 0 and mt[x - 1][y - 1].id != -1 and !ships[mt[x - 1][y - 1].id].check_state());
}

void Field::display_other_field() {
  notify(Notice::OtherField, "");
  std::vector<std::vector<char>> field_char(sz);
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      if (!mt[i][j].was_hit and !check_sunken_around(i, j)) {
        field_char[i].push_back('?');
      } else {
        if (mt[i][j].id == -1) {
          field_char[i].push_back('o');
        } else {
          field_char[i].push_back('x');
        }
      }
    }
  }
  draw_field(field_char);
}

void Field::display_own_field() const {
  notify(Notice::YourField, "");
  std::vector<std::vector<char>> field_char(sz);
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      if (mt[i][j].id == -1) {
        field_char[i].push_back('#');
      } else if (mt[i][j].was_hit) {
        field_char[i].push_back('x');
      } else {
        field_char[i].push_back(ships[mt[i][j].id].get_orient());
      }
    }
  }
  draw_field(field_char);
}
