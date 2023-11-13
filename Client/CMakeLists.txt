cmake_minimum_required(VERSION 2.8.4)

project(client) 

message(STATUS "start running cmake...")

add_executable(client game/src/initaliser.cpp 
                    game/src/main.cpp 
                    game/src/in_game.cpp
                    game/src/Help.cpp
                    game/src/get_keys.cpp 
                    game/src/animations_sprites.cpp 
                    game/src/menu.cpp 
                    game/src/SFML_graph.cpp
                    game/src/lobby.cpp
                    game/src/game_over.cpp
                    game/src/select_ship.cpp
                    game/src/custom_ships.cpp
                    game/src/power_ups.cpp
                    game/src/Inputs.cpp
                    game/src/tools.cpp
                    client/src/client.cpp
                    client/src/main.cpp
                    client/src/send_thread.cpp
                    client/src/sonar_thread.cpp )

TARGET_LINK_LIBRARIES(client sfml-graphics sfml-window sfml-audio sfml-system pthread)

set_property(TARGET client PROPERTY CXX_STANDARD 11)
