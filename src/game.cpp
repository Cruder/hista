#include <SFML/Window/Event.hpp>
#include "game.h"
#include "key_binding.h"
#include "gui/label.h"

namespace hista {
    const sf::Time game::FRAMERATE { sf::seconds(1.f/60.f) };

    game::game(unsigned int width, unsigned int height, const std::string& name)
    : _window { sf::VideoMode(width, height), name } {
        _window.setFramerateLimit(60);
        _window.setVerticalSyncEnabled(true);
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

        // Handle display here

        auto label = hista::gui::label("Hello World");

        _window.draw(label);

        _window.display();
    }
}
