cmake_minimum_required(VERSION 3.13)
project(battleship)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=undefined -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(CMAKE_EXECUTABLE_SUFFIX ".exe")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(include)
add_executable(battleship main.cpp)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

target_link_libraries(battleship Field Game IOManager Player Ships)
