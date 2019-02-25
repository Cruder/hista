#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Font.hpp>

#include "menu.h"

#include <iostream>

namespace hista {
    namespace state {
        static std::map<unsigned int, menu::options> mapper{
                {0, menu::options::Play},
                {1, menu::options::Exit}
        };

        menu::menu(stack &stack, context ctx) : base(stack, ctx), _options{}, _options_index{0}, font{}, background{},
                                                background_displayer{} {
            background.loadFromFile("../assets/images/back.png");
            background_displayer.setTexture(background);
            background_displayer.scale(1.7, 1.7);
            background_displayer.setPosition((_ctx.window->getView().getSize() -
                                              sf::Vector2(background_displayer.getGlobalBounds().width,
                                                          background_displayer.getGlobalBounds().height)) / 2.0f);

            font.loadFromFile("../assets/fonts/joystix.ttf");

            sf::Text play_option;
            play_option.setFont(font);
            play_option.setString("Play");
            play_option.setPosition((_ctx.window->getView().getSize() - sf::Vector2(play_option.getGlobalBounds().width, play_option.getGlobalBounds().height)) / 2.f);
            _options.push_back(play_option);

            sf::Text exit_option;
            exit_option.setFont(font);
            exit_option.setString("Exit");
            exit_option.setPosition(play_option.getPosition() + sf::Vector2f(0.f, 30.f));
            _options.push_back(exit_option);

            update_option_text();
        }

        void menu::draw() {
            sf::RenderWindow &window = *get_context().window;

            window.setView(window.getDefaultView());

            window.draw(background_displayer);
            for (const sf::Text &text : _options) {
                window.draw(text);
            }
        }

        bool menu::update(sf::Time) {
            return true;
        }

        bool menu::handle_event(const sf::Event &event) {
            if (event.type != sf::Event::KeyPressed)
                return false;

            if (event.key.code == sf::Keyboard::Return) {
                if (mapper[_options_index] == options::Play) {
                    request_stack_pop();
                    request_stack_push(ID::Game);
                } else if (mapper[_options_index] == options::Exit) {
                    request_stack_pop();
                }
            } else if (event.key.code == sf::Keyboard::Up) {
                if (_options_index > 0) {
                    _options_index--;
                } else {
                    _options_index = (unsigned int) _options.size() - 1;
                }

                update_option_text();
            } else if (event.key.code == sf::Keyboard::Down) {
                if (_options_index < _options.size() - 1) {
                    _options_index++;
                } else {
                    _options_index = 0;
                }

                update_option_text();
            }

            return true;
        }

        void menu::update_option_text() {
            if (_options.empty())
                return;

            for (sf::Text &text : _options) {
                text.setFillColor(sf::Color::White);
            }

            _options[_options_index].setFillColor(sf::Color::Red);
        }

    }
}
