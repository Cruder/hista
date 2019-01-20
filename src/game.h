#ifndef HISTA_PROJECT_GAME_H
#define HISTA_PROJECT_GAME_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "player/displayer.h"
#include "level.h"

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
        sf::Texture _texture;
        sf::RenderWindow _window;

        std::unique_ptr<level> _level;
        player::displayer _mario;
    };
}

#endif //HISTA_PROJECT_GAME_H
