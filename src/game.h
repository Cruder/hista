#ifndef HISTA_PROJECT_GAME_H
#define HISTA_PROJECT_GAME_H

#include <map>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "level.h"
#include "entity/animation.h"
#include "entity/enemy.h"
#include "entity/mario.h"

#include "state/stack.h"
#include "state/base.h"

namespace hista {
    class game final {
    public:
        game(unsigned int width, unsigned int height, const std::string& name);
        int run();

    private:
        void process_events();
        void update(sf::Time delta_time);
        void render();

    private:
        static const sf::Time FRAMERATE;
        sf::RenderWindow _window;

        state::stack stack;

        std::unique_ptr<entity::enemy> slime;
    };
}

#endif //HISTA_PROJECT_GAME_H
