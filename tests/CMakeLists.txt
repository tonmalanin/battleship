include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of googletest")

FetchContent_MakeAvailable(googletest)

add_executable(Tests
        MainTests.cpp
        FieldTestCase.cpp
        GameTestCase.cpp
        IOTestCase.cpp
        PlayerTestCase.cpp
        ShipTestCase.cpp
)

target_include_directories(Tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(Tests PRIVATE gtest gtest_main
        Field Game Player IOManager Ships
)

set_target_properties(Tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

enable_testing()
add_test(NAME BattleshipTests COMMAND Tests)