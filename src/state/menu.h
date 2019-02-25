#ifndef STATE_MENU_H
#define STATE_MENU_H

#include "base.h"
#include <SFML/Graphics/Text.hpp>

namespace hista {
    namespace state {
        class menu : public base {
        public:
            menu(stack &stack, context ctx);

            void draw() override;

            bool update(sf::Time) override;

            bool handle_event(const sf::Event &event) override;

        private:
            void update_option_text();

        private:
            std::vector<sf::Text> _options;
            unsigned int _options_index;
            sf::Font font;
        public:
            enum class options {
                Play,
                Exit
            };
        };
    }
}

#endif // STATE_MENU_H
