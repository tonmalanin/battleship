#include "../include/IOManager.h"

void start_message() {
  system("clear");
  std::cout << "Game started" << std::endl;
}

void finish_message(std::string &winner) {
  sleep(2);
  system("clear");
  std::cout << "Player " << winner << " won";
}

std::string greetings(int id) {
  sleep(2);
  system("clear");
  std::cout << "You're player " << id << ". Enter you name: ";
  std::string name;
  std::cin >> name;
  return name;
}

void shot_results_report(int state) {
  std::cout << "Executing shot" << std::endl;
  switch (state) {
    case 0:
      std::cout << "Sunk!" << std::endl;
      break;
    case 1:
      std::cout << "Hit!" << std::endl;
      break;
    case -1:
      std::cout << "Miss!" << std::endl;
      break;
  }
}

void display_ship(char orient) {
  if (orient == 'n') {
    std::cout << "^ ";
  } else if (orient == 'w') {
    std::cout << "< ";
  } else if (orient == 's') {
    std::cout << "v ";
  } else if (orient == 'e') {
    std::cout << "> ";
  } else {
    std::cout << orient << " ";
  }
}

void draw_field(std::vector<std::vector<char>> &field_char) {
  std::cout << "  ";
  for (int i = 0; i < 10; ++i) {
    char column = 'A' + i;
    std::cout << column << ' ';
  }
  std::cout << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::cout << i << ' ';
    for (int j = 0; j < 10; ++j) {
      display_ship(field_char[i][j]);
    }
    std::cout << std::endl;
  }
}

void report_error(Error err) {
  switch (err) {
    case Error::Coords:
      std::cout << "Out of bounds! Enter again!" << std::endl;
      break;
    case Error::Shot:
      std::cout << "You've already shot there! Enter the coordinates again!" << std::endl;
      break;
    case Error::Surroundings:
      std::cout << "The new ship touches with the old one! Enter again!" << std::endl;
      break;
  }
}

std::string get_coords(int size) {
  if (size == 0) {
    std::cout << "Enter the coordinates: ";
  } else {
    std::cout << "Enter the coordinates of the bow of a ship of length " << size << ": ";
  }
  std::string coords;
  std::cin >> coords;
  if (coords.size() != 2 or coords[0] < 'A' or coords[0] > 'J' or coords[1] < '0' or coords[1] > '9') {
    std::cout << "Incorrect coordinates! Enter again!" << std::endl;
    throw std::exception();
  }
  return coords;
}

std::string get_orient() {
  std::string orient;
  while (true) {
    std::cout << "Enter ship orientation (n/e/s/w): ";
    std::cin >> orient;
    if (orient.size() != 1 or (orient[0] != 'n' and orient[0] != 'e' and orient[0] != 's' and orient[0] != 'w')) {
      std::cout << "Incorrect orientation! Enter again!" << std::endl;
      continue;
    }
    break;
  }
  return orient;
}

void notify(Notice note, const std::string &name) {
  if (note != Notice::OtherField) {
    sleep(2);
    system("clear");
  }
  switch (note) {
    case Notice::Place:
      std::cout << "Place your ships, " << name << std::endl;
      break;
    case Notice::Move:
      std::cout << "Make your move, " << name << std::endl;
      break;
    case Notice::YourField:
      std::cout << "Your field:" << std::endl;
      break;
    case Notice::OtherField:
      std::cout << "Enemy's field:" << std::endl;
      break;
    case Notice::EnemyMove:
      std::cout << "Your enemy is making move" << std::endl;
      break;
  }
}

void settings_change_report(Settings param, bool &state) {
  char fl;
  switch (param) {
    case Settings::Random:
      std::cout << "Place ships randomly? (y/n): ";
      std::cin >> fl;
      if (fl == 'y') {
        state = true;
      }
      break;
    case Settings::Mode:
      std::cout << "Choose mode (1/2): ";
      std::cin >> fl;
      if (fl == '1') {
        state = true;
        std::cout << "Single mode" << std::endl;
      } else {
        std::cout << "Couple mode" << std::endl;
      }
      break;
  }
}