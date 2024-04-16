#pragma once

#include <iostream>
#include <unistd.h>
#include <vector>

void start_message();

void finish_message(std::string &winner);

std::string greetings(int id);

void shot_results_report(int state);

void display_ship(char orient);

void draw_field(std::vector<std::vector<char>> &field_char);

enum class Error { Coords,
                   Shot,
                   Surroundings };

void report_error(Error err);

std::string get_coords(int size);

std::string get_orient();

enum class Notice { Place,
                    Move,
                    YourField,
                    OtherField };

void notify(Notice note, const std::string &player);

void settings_change_report(bool &is_random);