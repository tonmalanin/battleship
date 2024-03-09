#include "../include/Ships.h"

Ship::Ship(int sz, char orient) : sz(sz), state(sz), orient(orient) {
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

void Ship::display_ship() const{
  if (orient == 'n') {
    std::cout << "^ ";
  } else if (orient == 'w') {
    std::cout << "< ";
  } else if (orient == 's') {
    std::cout << "v ";
  } else {
    std::cout << "> ";
  }
}