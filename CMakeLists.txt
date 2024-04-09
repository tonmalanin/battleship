cmake_minimum_required(VERSION 3.22)
project(battleship)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++20")
set(CMAKE_EXECUTABLE_SUFFIX ".exe")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(battleship main.cpp
                            include/Field.h
                            include/Game.h
                            include/Player.h
                            include/Ships.h
                            include/IOManager.h
                            src/Field.cpp
                            src/Game.cpp
                            src/Player.cpp
                            src/Ships.cpp
                            src/IOManager.cpp)