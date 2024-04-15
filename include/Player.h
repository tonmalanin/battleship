#pragma once

#include <memory>
#include <string>
#include <random>
#include <chrono>

#include "Field.h"
#include "IOManager.h"

class Player {
 private:
  const static int kShipsNumber = 10;
  const static inline std::vector<int> ships_size = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};

  std::string name;
  Field fld;

 public:
  explicit Player(std::string &name, const Field &field);

  void place_ships();

  void fire(Player &other) const;

  std::string &get_name();

  bool lost();
};