#include "victory.h"

namespace hista {
    namespace state {

        victory::victory(stack &stack, context ctx) : base(stack, ctx), font{}, message{}, background{},
                                                      background_displayer{} {
            background.loadFromFile("../assets/images/victory.png");
            background_displayer.setTexture(background);
            background_displayer.scale(1.2, 1.2);
            background_displayer.setPosition((_ctx.window->getView().getSize() -
                                              sf::Vector2(background_displayer.getGlobalBounds().width,
                                                          background_displayer.getGlobalBounds().height)) / 2.0f);


            font.loadFromFile("../assets/fonts/joystix.ttf");

            message.setFont(font);
            message.setString("Victory !\nPress any key to continue . . .");
        }

        void victory::draw() {
            sf::RenderWindow &window = *get_context().window;
            window.setView(window.getDefaultView());

            window.draw(message);
            window.draw(background_displayer);
        }

        bool victory::update(sf::Time) {
            return false;
        }

        bool victory::handle_event(const sf::Event &event) {
            if (event.type == sf::Event::KeyPressed) {
                request_stack_pop();
                request_stack_push(ID::Game2);
                return true;
            }

            return false;
        }
    }
}
