#include "displayer.h"

namespace hista {
    namespace ennemi {

        displayer::displayer(ennemi::context context, const sf::Texture &texture) : _context { context }, _texture {texture} {
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(256, 56, 40, 32));
            _sprite.setScale(2,2);
            setPosition(context._x, context._y);
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_sprite, states);
        }

    }
}
