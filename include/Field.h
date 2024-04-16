#pragma once

#include <vector>

#include "IOManager.h"
#include "Ships.h"

class Field {
 private:
  const static int kSize = 10;

  struct Cell {
    bool was_hit = false;
    int id = -1;
    int part = 0;
  };

  int sz;
  std::vector<std::vector<Cell>> mt;
  int ships_num;
  std::vector<Ship> ships;

 public:
  explicit Field(int sz);

  Field();

  void create_ship(int lth, int x, int y, char orient, bool is_bot);

  void check_coords(int x, int y, bool is_bot) const;

  void check_shot(int x, int y);

  void hit_field(int x, int y);

  int get_ships_num() const;

  void check_surroundings(int x, int y, bool is_bot);

  void display_other_field();

  void display_own_field() const;
};