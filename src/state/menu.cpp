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

        menu::menu(stack &stack, context ctx) : base(stack, ctx), _options{}, _options_index{0}, font {} {
//            sf::Texture &texture = context.textures->get(Textures::TitleScreen);
//            sf::Font &font = context.fonts->get(Fonts::Main);

//            mBackgroundSprite.setTexture(texture);
            font.loadFromFile("../assets/fonts/joystix.ttf");

            sf::Text play_option;
            play_option.setFont(font);
            play_option.setString("Play");
            // centerOrigin(play_option);
            play_option.setPosition(_ctx.window->getView().getSize() / 2.f);
            _options.push_back(play_option);

            sf::Text exit_option;
            exit_option.setFont(font);
            exit_option.setString("Exit");
            // centerOrigin(exitOption);
            exit_option.setPosition(play_option.getPosition() + sf::Vector2f(0.f, 30.f));
            _options.push_back(exit_option);

            update_option_text();
        }

        void menu::draw() {
            std::cerr << "Hello 1" << std::endl;
            sf::RenderWindow &window = *get_context().window;
            std::cerr << "Hello 2" << std::endl;

            window.setView(window.getDefaultView());
            std::cerr << "Hello 3" << std::endl;
//            window.draw(mBackgroundSprite);

            for (const sf::Text &text : _options) {
                std::cerr << "Hello 4 - " << text.getString().toAnsiString() << std::endl;
                window.draw(text);
                std::cerr << "Hello 5" << std::endl;
            }
        }

        bool menu::update(sf::Time) {
            return true;
        }

        bool menu::handle_event(const sf::Event &event) {
            // The demonstration menu logic
            if (event.type != sf::Event::KeyPressed)
                return false;

            if (event.key.code == sf::Keyboard::Return) {
                if (mapper[_options_index] == options::Play) {
                    request_stack_pop();
//                    request_stack_push(States::Game);
                } else if (mapper[_options_index] == options::Exit) {
                    // The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
                    request_stack_pop();
                }
            } else if (event.key.code == sf::Keyboard::Up) {
                // Decrement and wrap-around
                if (_options_index > 0) {
                    _options_index--;
                } else {
                    _options_index = (unsigned int) _options.size() - 1;
                }

                update_option_text();
            } else if (event.key.code == sf::Keyboard::Down) {
                // Increment and wrap-around
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

            // White all texts
            for (sf::Text &text : _options) {
                text.setFillColor(sf::Color::White);
            }

            // Red the selected text
            _options[_options_index].setFillColor(sf::Color::Red);
        }

    }
}
