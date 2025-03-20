#pragma once

#include <unistd.h>

#include <iostream>
#include <vector>

void start_message();

void finish_message(std::string& winner);

std::string greetings(int id);

void shot_results_report(int state);

void display_ship(char orient);

void draw_field(std::vector<std::vector<char>>& field_char);

struct Error {
  virtual void report() = 0;
};

struct CoordsError : public Error {
  void report() final;
};

struct ShotError : public Error {
  void report() final;
};

struct SurroundingsError : public Error {
  void report() final;
};

void report_error(Error* err);

std::string get_coords(int size);

std::string get_orient();

struct Notice {
  virtual void notify(const std::string& name) = 0;
};

struct PlaceNotice : public Notice {
  void notify(const std::string& name) final;
};

struct MoveNotice : public Notice {
  void notify(const std::string& name) final;
};

struct YourFieldNotice : public Notice {
  void notify(const std::string&) final;
};

struct OtherFieldNotice : public Notice {
  void notify(const std::string&) final;
};

struct EnemyMoveNotice : public Notice {
  void notify(const std::string&) final;
};

void notify(Notice* note, const std::string& player);

struct Settings {
  virtual void change(bool& state) = 0;
};

struct ModeSettings : public Settings {
  void change(bool& state) final;
};

struct RandomSettings : public Settings {
  void change(bool& state) final;
};

void settings_change_report(Settings* param, bool& state);