//
// Created by necros on 25/02/19.
//

#include "defeat.h"

namespace hista {
    namespace state {

        defeat::defeat(stack &stack, context ctx) : base(stack, ctx), font{}, message{} {
            font.loadFromFile("../assets/fonts/joystix.ttf");

            message.setFont(font);
            message.setString("Defeat !\nPress any key to continue . . .");
        }

        void defeat::draw() {
            sf::RenderWindow &window = *get_context().window;
            window.setView(window.getDefaultView());

            window.draw(message);
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
