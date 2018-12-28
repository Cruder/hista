//
// Created by necros on 28/12/18.
//

#include "label.h"

namespace hista {
    namespace gui {
        // Set a font
        label::label(const std::string &text) {
        }

        void label::handle_event(const sf::Event &event) {
        }

        void label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_text, states);
        }
    }
}
