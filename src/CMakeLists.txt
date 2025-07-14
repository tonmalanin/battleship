add_library(Field Field.cpp)
add_library(Game Game.cpp)
add_library(IOManager IOManager.cpp)
add_library(Player Player.cpp)
add_library(Ships Ships.cpp)

# Указываем зависимости
target_link_libraries(Field PRIVATE IOManager Ships)
target_link_libraries(Player PRIVATE Field IOManager)
target_link_libraries(Game PRIVATE Field Player IOManager)
