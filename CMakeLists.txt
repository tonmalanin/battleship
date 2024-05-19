cmake_minimum_required(VERSION 3.13)
project(battleship)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=undefined -fsanitize=address")
set(CMAKE_EXECUTABLE_SUFFIX ".exe")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(include)
add_executable(battleship main.cpp)

add_subdirectory(src)
target_link_libraries(battleship Field Game IOManager Player Ships)
