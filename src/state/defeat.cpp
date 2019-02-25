//
// Created by necros on 25/02/19.
//

#include "defeat.h"

namespace hista {
    namespace state {

        defeat::defeat(stack &stack, context ctx) : base(stack, ctx), font{}, message{}, background{},
                                                    background_displayer{} {
            background.loadFromFile("../assets/images/lose.png");
            background_displayer.setTexture(background);
            background_displayer.scale(1.2, 1.2);
            background_displayer.setPosition((_ctx.window->getView().getSize() -
                                              sf::Vector2(background_displayer.getGlobalBounds().width,
                                                          background_displayer.getGlobalBounds().height)) / 2.0f);

            font.loadFromFile("../assets/fonts/joystix.ttf");

            message.setFont(font);
            message.setString("Defeat !\nPress any key to continue . . .");
        }

        void defeat::draw() {
            sf::RenderWindow &window = *get_context().window;
            window.setView(window.getDefaultView());

            window.draw(message);
            window.draw(background_displayer);
        }

        bool defeat::update(sf::Time) {
            return false;
        }

        bool defeat::handle_event(const sf::Event &event) {
            if (event.type == sf::Event::KeyPressed) {
                request_stack_pop();
                return true;
            }

            return false;
        }
    }
}
