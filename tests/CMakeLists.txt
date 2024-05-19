find_package(GTest)

add_executable(Tests EXCLUDE_FROM_ALL MainTests.cpp FieldTestCase.cpp GameTestCase.cpp IOTestCase.cpp)
target_link_libraries(Tests PUBLIC ${GTEST_LIBRARIES} Field Game Player IOManager)