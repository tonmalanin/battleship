#pragma once

#include <chrono>
#include <memory>
#include <random>
#include <string>

#include "Field.h"
#include "IOManager.h"

class Player {
 private:
  const static int kShipsNumber = 10;
  const static inline std::vector<int> ships_size = {1, 1, 1, 1, 2,
                                                     2, 2, 3, 3, 4};

  std::string name;
  Field fld;
  bool is_bot;

 public:
  explicit Player(std::string& name, Field&& field, bool is_bot);

  void place_ships();

  void fire(Player& other) const;

  std::string& get_name();

  bool lost();

  bool operator==(const Player& other) const = default;
};