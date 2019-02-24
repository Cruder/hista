//
// Created by necros on 24/02/19.
//

#include "game.h"

namespace hista {
    namespace state {

        game::game(stack &stack, context ctx) : base(stack, ctx),
                                                _mario{player::context(400u, 400u)},
                                                _level{make_level("../assets/meta/level/1.hista")} {
        }

        void game::draw() {
            auto window = _ctx.window;

            window->draw(_mario);
            window->draw(*_level);
        }

        bool game::update(sf::Time dt) {
            _mario.update(dt.asSeconds());

            return false;
        }

        bool game::handle_event(const sf::Event &event) {
            if (event.key.code == sf::Keyboard::Escape) {
                request_stack_pop();
                request_stack_push(ID::Menu);
            }

            return false;
        }
    }
}
