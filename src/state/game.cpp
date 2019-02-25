//
// Created by necros on 24/02/19.
//

#include "game.h"
#include "../key_binding.h"

namespace hista {
    namespace state {

        game::game(stack &stack, context ctx) : base(stack, ctx),
                                                _mario{entity::make_mario("../assets/meta/mario/mario.hista",
                                                                          sf::Vector2f(400, 400))},
                                                _level{make_level("../assets/meta/level/1.hista")} {
        }

        void game::draw() {
            auto window = _ctx.window;

            window->draw(*_mario);
            window->draw(*_level);
        }

        bool game::update(sf::Time dt) {
            _mario->update(dt);

            return false;
        }

        bool game::handle_event(const sf::Event &event) {
            auto binding = key_binding{};
            if (event.key.code == sf::Keyboard::Escape) {
                request_stack_pop();
                request_stack_push(ID::Menu);
            }

            for (const auto &action : binding.actions()) {
                _mario->start_movement(action);
            }

            return false;
        }
    }
}
