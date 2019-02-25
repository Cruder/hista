#include "game.h"
#include "../key_binding.h"

namespace hista {
    namespace state {

        game::game(stack &stack, context ctx, std::unique_ptr<level>&& level) : base(stack, ctx),
                                                _mario{entity::make_mario("../assets/meta/mario/mario.hista",
                                                                          sf::Vector2f(400, 400))},
                                                _level{std::move(level)} {
        }

        void game::draw() {
            auto window = _ctx.window;

            window->draw(*_mario);
            for (const auto &slime : _slimes) {
                window->draw(*slime);
            }
            window->draw(*_level);
        }

        bool game::update(sf::Time dt) {
            _mario->update(dt);

            for (const auto &slime : _slimes) {
                slime->update(dt);
            }

            return false;
        }

        bool game::handle_event(const sf::Event &event) {
            if (event.type == sf::Event::KeyPressed) {
                auto binding = key_binding{};
                if (event.key.code == sf::Keyboard::Escape) {
                    request_stack_pop();
                    request_stack_push(ID::Menu);
                }

                if (event.key.code == sf::Keyboard::P) {
                    request_stack_pop();
                    request_stack_push(ID::Win);
                }

                if (event.key.code == sf::Keyboard::Q) {
                    request_stack_pop();
                    request_stack_push(ID::Lose);
                }

                for (const auto &action : binding.actions()) {
                    _mario->start_movement(action);
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position = sf::Mouse::getPosition();
                sf::Vector2f convert = sf::Vector2f(position.x - 1000, position.y);

                _slimes.push_back(entity::make_enemy("../assets/meta/enemy/slime.hista", convert));
            }

            return false;
        }
    }
}
