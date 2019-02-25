//
// Created by necros on 25/02/19.
//

#ifndef HISTA_PROJECT_VICTORY_STATE_H
#define HISTA_PROJECT_VICTORY_STATE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "base.h"

namespace hista {
    namespace state {
        class victory : public base {
        public:
            victory(stack &stack, context ctx);

            void draw() override;

            bool update(sf::Time) override;

            bool handle_event(const sf::Event &event) override;

        private:
            sf::Font font;
            sf::Text message;
        };
    }
}

#endif //HISTA_PROJECT_VICTORY_H
