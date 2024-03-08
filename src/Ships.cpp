#include "../include/Ships.h"

Ship::Ship(int sz) : sz(sz), state(sz) {
  parts.resize(sz, true);
}

void Ship::get_shot(int part) {
  parts[part] = false;
  --state;
  if (state == 0) {
    std::cout << "Sunk!" << std::endl;
  } else {
    std::cout << "Hit!" << std::endl;
  }
}

bool Ship::check_state() const {
  return state > 0;
}