#pragma once

#include <iostream>

#include "Field.h"

class Player {
 private:
  const static int kShipsNumber = 10;
  const static inline std::vector<int> ships_size = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};

  int id;
  Field fld;

 public:
  explicit Player(int id, const Field &field);

  void place_ships();

  void fire(Player *other) const;

  int get_id() const;

  bool lost();
};