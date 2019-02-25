#ifndef STATE_MENU_H
#define STATE_MENU_H

#include "base.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

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

            sf::Texture background;
            sf::Sprite background_displayer;
        public:
            enum class options {
                Play,
                Exit
            };
        };
    }
}

#endif // STATE_MENU_H
