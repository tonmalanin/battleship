#include "../include/Ships.h"

Ship::Ship(int sz, char orient) : sz(sz), state(sz), orient(orient) {
  parts.resize(sz, true);
}

void Ship::get_shot(int part) {
  parts[part] = false;
  --state;
}

bool Ship::check_state() const {
  return state > 0;
}

char Ship::get_orient() const {
  return orient;
}