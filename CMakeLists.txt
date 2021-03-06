cmake_minimum_required(VERSION 3.12)
project(hista_project)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED system window graphics network audio)

add_executable(hista_project
    src/main.cpp
    src/key_binding.cpp src/key_binding.h
    src/player/context.h
    src/game.cpp src/game.h
    src/gui/container.cpp src/gui/container.h
    src/gui/component.cpp src/gui/component.h
    src/gui/button.cpp src/gui/button.h
    src/gui/label.cpp src/gui/label.h
    src/resource/holder.inl src/resource/holder.h
    src/resource/identifier.h
    src/ennemi/actions.h
    src/ennemi/context.h
    src/ennemi/displayer.cpp src/ennemi/displayer.h
    src/behavior/movable.h
    src/level.cpp src/level.h
    src/tilemap.cpp src/tilemap.h
    src/tileset.cpp src/tileset.h
    src/entity/animation.cpp src/entity/animation.h
    src/state/base.cpp src/state/base.h
    src/state/stack.cpp src/state/stack.h
    src/state/menu.cpp src/state/menu.h
    src/state/identifier.h
    src/state/context.cpp src/state/context.h
    src/state/game.cpp src/state/game.h
    src/entity/enemy.cpp src/entity/enemy.h
    src/entity/mario.cpp src/entity/mario.h
        src/state/victory.cpp src/state/victory.h src/state/defeat.cpp src/state/defeat.h src/state/level1.cpp src/state/level1.h src/state/level2.cpp src/state/level2.h)

target_link_libraries(hista_project sfml-window sfml-graphics sfml-network sfml-audio)
