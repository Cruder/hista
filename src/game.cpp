#include <SFML/Window/Event.hpp>
#include <iostream>
#include "game.h"
#include "key_binding.h"
#include "gui/label.h"
#include "ennemi/displayer.h"
#include "ennemi/context.h"
#include "state/menu.h"
#include "state/game.h"
#include "state/victory.h"
#include "state/defeat.h"
#include "state/level1.h"
#include "state/level2.h"

#define ACTION_TIME 0.2
#define FRAME_RATE 60

namespace hista {
    game::game(unsigned int width, unsigned int height, const std::string &name)
            : _window{sf::VideoMode(width, height), name},
              stack{state::context{_window}} {
        _window.setFramerateLimit(60);
        _window.setVerticalSyncEnabled(true);


        stack.register_state<state::menu>(state::ID::Menu);
        stack.register_state<hista::state::level1>(state::ID::Game1);
        stack.register_state<hista::state::level2>(state::ID::Game2);
        stack.register_state<hista::state::victory>(state::ID::Win);
        stack.register_state<hista::state::defeat>(state::ID::Lose);
        stack.push_state(state::ID::Menu);
    }

    int game::run() {
        sf::Clock clock{};
        sf::Time accumulator{sf::Time::Zero};

        while (_window.isOpen()) {
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
        sf::Event event{};
        hista::key_binding binding{};

        while (_window.pollEvent(event)) {
            stack.handle_event(event);
            if (event.type == sf::Event::Closed) { _window.close(); }

            if (stack.empty()) {
                _window.close();
            }
        }
    }

    void game::update(sf::Time delta_time) {
        stack.update(delta_time);
    }

    void game::render() {
        _window.clear(sf::Color::Black);

        stack.draw();

        _window.display();
    }
}
