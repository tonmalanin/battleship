#pragma once

#include <iostream>
#include <vector>

class Ship {
 private:
  int sz;
  int state;
  std::vector<bool> parts;

 public:
  explicit Ship(int sz);

  void get_shot(int part);

  bool check_state() const;
};