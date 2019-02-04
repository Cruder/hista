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
    : _window { sf::VideoMode(width, height), name }, _map{},
      _mario { hista::player::displayer(hista::player::context(400u, 400u)) }
    {
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
//                std::cout << (int)action <<std::endl;
                switch (action){
                    case player::actions::MOVE_LEFT:
                        std::cout << "LEFT\n";
                        if(_map["LEFT"] <= 0) _map["LEFT"] = 1.f;

                        break;
                    case player::actions::MOVE_RIGHT :
                        std::cout << "RIGHT\n";
                        if(_map["RIGHT"] <= 0) _map["RIGHT"] = 1.f;
                        break;


//                std::cout << (int)action <<std::endl;

                }
            }

        }
    }

    void game::update(sf::Time delta_time) {
        if(_map["LEFT"] > 0){
            _mario.left();
            _map["LEFT"] -= FRAMERATE.asSeconds()*3;
//            std::cout<<"LOCK: "<< _map["LEFT"] << std::endl;
        }
        if(_map["RIGHT"] > 0){
            _mario.right();
            _map["RIGHT"] -= FRAMERATE.asSeconds()*3;
//            std::cout<<"LOCK: "<< _map["RIGHT"] << std::endl;
        }
    }

    void game::render() {
        _window.clear(sf::Color::Black);

        auto label = hista::gui::label("Hello World");
        auto ctx_ennemi = hista::ennemi::context(200u, 400u);
        auto ennemi = hista::ennemi::displayer(ctx_ennemi, _texture);

        _window.draw(label);
        _window.draw(_mario);
        _window.draw(ennemi);

        _window.display();
    }
}
