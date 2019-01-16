#include "displayer.h"

namespace hista {
    namespace player {
        displayer::displayer(player::context context) : _context { context } {
            _texture.loadFromFile("../assets/images/textures.png");
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(132, 48, 24, 32));
            setPosition(context._x, context._y);
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_sprite, states);
        }
    }
}
