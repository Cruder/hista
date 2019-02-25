//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT__STATE_GAME_H
#define HISTA_PROJECT__STATE_GAME_H

#include "../player/player.h"
#include "../level.h"
#include "base.h"

namespace hista {
    namespace state {
        class game : public base {
        public:
            game(stack &stack, context ctx);

            void draw() override;

            bool update(sf::Time) override;

            bool handle_event(const sf::Event &event) override;

        private:
            player::player _mario;
            std::unique_ptr<level> _level;
        };
    }
}

#endif //HISTA_PROJECT_GAME_H
