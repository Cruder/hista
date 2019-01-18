#include <SFML/Window/Event.hpp>
#include "game.h"
#include "key_binding.h"
#include "gui/label.h"
#include "player/displayer.h"
#include "player/context.h"
#include "ennemi/displayer_enemy.h"
#include "ennemi/context_enemy.h"

namespace hista {
    const sf::Time game::FRAMERATE { sf::seconds(1.f/60.f) };

    game::game(unsigned int width, unsigned int height, const std::string& name)
    : _window { sf::VideoMode(width, height), name } {
        _window.setFramerateLimit(60);
        _window.setVerticalSyncEnabled(true);
        _texture.loadFromFile("../assets/images/textures.png");
    }

    int game::run() {
        sf::Clock clock {};
        sf::Time accumulator { sf::Time::Zero };


        while(_window.isOpen()) {
            sf::Time delta_time = clock.restart();

            process_events();
            update(delta_time);
            render();
        }

        return 0;
    }

    /*
     * TODO: Queue for handling multiples input
     */
    void game::process_events() {
        sf::Event event {};
        hista::key_binding binding {};

        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
            for(const auto &action : binding.actions()) {
                // Handle actions here
            }
        }
    }

    void game::update(sf::Time delta_time) {
    }

    void game::render() {
        _window.clear(sf::Color::Black);

        auto label = hista::gui::label("Hello World");
        auto ctx = hista::player::context(400u, 400u);
        auto player = hista::player::displayer(ctx);
        auto ctx_ennemi = hista::ennemi::context_enemy(200u, 400u);
        auto ennemi = hista::ennemi::displayer_enemy(ctx_ennemi,_texture);

        _window.draw(label);
        _window.draw(player);
        _window.draw(ennemi);

        _window.display();
    }
}
