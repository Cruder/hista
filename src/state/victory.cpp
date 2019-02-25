//
// Created by necros on 25/02/19.
//

#include "victory.h"

namespace hista {
    namespace state {

        victory::victory(stack &stack, context ctx) : base(stack, ctx), font{}, message{} {
            font.loadFromFile("../assets/fonts/joystix.ttf");

            message.setFont(font);
            message.setString("Victory !\nPress any key to continue . . .");
        }

        void victory::draw() {
            sf::RenderWindow &window = *get_context().window;
            window.setView(window.getDefaultView());

            window.draw(message);
        }

        bool victory::update(sf::Time) {
            return false;
        }

        bool victory::handle_event(const sf::Event &event) {
            if (event.type == sf::Event::KeyPressed) {
                request_stack_pop();
                return true;
            }

            return false;
        }
    }
}
