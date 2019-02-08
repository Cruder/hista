#include "displayer.h"

namespace hista {
    namespace player {
        displayer::displayer() {
            _texture.loadFromFile("../assets/images/textures.png");
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(66, 24, 12, 16));
            _sprite.setScale(2, 2);
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
            states.transform *= getTransform();
            target.draw(_sprite, states);
        }

    }
}
