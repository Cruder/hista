#include <SFML/Window/Event.hpp>
#include <iostream>
#include "game.h"
#include "key_binding.h"
#include "gui/label.h"
#include "player/displayer.h"
#include "player/context.h"
#include "ennemi/displayer.h"
#include "ennemi/context.h"

namespace hista {
    const sf::Time game::FRAMERATE { sf::seconds(1.f/60.f) };

    game::game(unsigned int width, unsigned int height, const std::string& name)
    : _window { sf::VideoMode(width, height), name },
      _level { make_level("../assets/meta/level/1.hista") },
      _mario { player::context(0, 0), sf::Texture() } {
        _window.setFramerateLimit(60);
        _window.setVerticalSyncEnabled(true);
        _texture.loadFromFile("../assets/images/textures.png");

        _level->setPosition(150.0f, 150.0f);
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
                std::cout << (int)action <<std::endl;
                switch (action){
                    case player::actions::MOVE_LEFT:
                        std::cout << "LEFT\n";
                        _mario.left();
                        break;
                    case player::actions::MOVE_RIGHT :
                        std::cout << "RIGHT\n";
                        _mario.right();
                        break;


//                std::cout << (int)action <<std::endl;

                }
            }
        }
    }

    void game::update(sf::Time delta_time) {
    }

    void game::render() {
        _window.clear(sf::Color::Black);

        auto label = hista::gui::label("Hello World");
        auto player_ctx = hista::player::context(400u, 400u);
        auto player = hista::player::displayer(player_ctx, _texture);
        auto ennemi_ctx = hista::ennemi::context(200u, 400u);
        auto ennemi = hista::ennemi::displayer(ennemi_ctx, _texture);

        _window.draw(label);
        _window.draw(_mario);
        _window.draw(ennemi);

        _window.draw(*_level);

        _window.display();
    }
}
