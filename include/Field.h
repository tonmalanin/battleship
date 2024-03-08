#pragma once

#include <iostream>
#include <vector>

#include "Ships.h"

class Field {
 private:
  const static int kSize = 10;

  struct Cell {
    bool was_hit = false;
    Ship *id = nullptr;
    int part = 0;
  };

  int sz;
  std::vector<std::vector<Cell>> mt;
  int ships_num;

 public:
  explicit Field(int sz);

  Field();

  void create_ship(int lth, int x, int y, char orient);

  void check_coords(int x, int y) const;

  void check_shot(int x, int y);

  void hit_field(int x, int y);

  int get_ships() const;

  void check_surroundings(int x, int y);
};