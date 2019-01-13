#include "label.h"

namespace hista {
    namespace gui {
        // TODO: Set a font from holder
        label::label(const std::string &text) {
            _font = sf::Font();
            _font.loadFromFile("../assets/fonts/joystix.ttf");
            _text = sf::Text(text, _font);
        }

        void label::handle_event(const sf::Event &event) {
        }

        void label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_text, states);
        }
    }
}
