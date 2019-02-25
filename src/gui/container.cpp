#include "container.h"

namespace hista {
    namespace gui {
        void container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();

            for (const auto &child : _children) {
                target.draw(*child, states);
            }
        }

        void container::select(unsigned int index) {

        }
    }
}
