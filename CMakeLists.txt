cmake_minimum_required(VERSION 3.12)
project(hista_project)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED system window graphics network audio)

add_executable(hista_project src/main.cpp src/key_binding.cpp src/key_binding.h src/player/actions.h src/player/displayer.h src/player/context.h src/game.cpp src/game.h)
target_link_libraries(hista_project sfml-window sfml-graphics sfml-network sfml-audio)
