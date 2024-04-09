#pragma once

#include <vector>

class Ship {
 private:
  int sz;
  int state;
  std::vector<bool> parts;
  char orient;

 public:
  explicit Ship(int sz, char orient);

  void get_shot(int part);

  bool check_state() const;

  char get_orient() const;
};