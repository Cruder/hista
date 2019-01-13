#ifndef HISTA_PROJECT_GAME_H
#define HISTA_PROJECT_GAME_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

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
    };
}

#endif //HISTA_PROJECT_GAME_H
