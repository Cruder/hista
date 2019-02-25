//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT__STATE_GAME_H
#define HISTA_PROJECT__STATE_GAME_H

#include "../level.h"
#include "../entity/mario.h"
#include "base.h"
#include "../entity/enemy.h"

namespace hista {
    namespace state {
        class game : public base {
        public:
            game(stack &stack, context ctx, std::unique_ptr<level>&& level);

            void draw() override;

            bool update(sf::Time) override;

            bool handle_event(const sf::Event &event) override;

        private:
            std::unique_ptr<entity::mario> _mario;
            std::unique_ptr<level> _level;

            std::vector<std::unique_ptr<entity::enemy>> _slimes;
        };
    }
}

#endif //HISTA_PROJECT_GAME_H
