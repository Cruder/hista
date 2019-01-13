#ifndef HISTA_PROJECT_LABEL_H
#define HISTA_PROJECT_LABEL_H

#include <SFML/Graphics/Text.hpp>
#include "component.h"

namespace hista {
    namespace gui {
        class label : public component {
        public:
            explicit label(const std::string& text);

            void handle_event(const sf::Event& event) override;
        private:
            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        private:
            sf::Text _text;
        };
    }
}

#endif //HISTA_PROJECT_LABEL_H
