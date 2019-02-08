cmake_minimum_required(VERSION 3.12)
project(hista_project)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED system window graphics network audio)

add_executable(hista_project src/main.cpp src/key_binding.cpp src/key_binding.h src/player/actions.h src/player/displayer.cpp src/player/displayer.h src/player/context.cpp src/player/context.h src/game.cpp src/game.h src/gui/container.cpp src/gui/container.h src/gui/component.cpp src/gui/component.h src/gui/button.cpp src/gui/button.h src/gui/label.cpp src/gui/label.h src/resource/holder.inl src/resource/holder.h src/resource/identifier.h src/state.cpp src/state.h src/ennemi/actions.h src/ennemi/context.h src/ennemi/displayer.cpp src/ennemi/displayer.h src/behavior/Movable.h src/player/playerUpdater.cpp src/player/playerUpdater.h src/player/player.cpp src/player/player.h src/level.cpp src/level.h src/tilemap.cpp src/tilemap.h src/tileset.cpp src/tileset.h)
target_link_libraries(hista_project sfml-window sfml-graphics sfml-network sfml-audio)
