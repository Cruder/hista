#include "displayer.h"

namespace hista {
    namespace player {
        displayer::displayer(player::context context) : _context { context } {
            _texture.loadFromFile("../assets/images/textures.png");
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(66, 24, 12, 16));
            _sprite.setScale(2, 2);
            setPosition(context._x, context._y);
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_sprite, states);
        }

        void displayer::left() {
            if(_context._x>0)
                _context._x--;
            setPosition(_context._x,_context._y);
        }

        void displayer::right() {
//            if(_context._x < 500)
              _context._x++;
            setPosition(_context._x,_context._y);
        }

        void displayer::down() {

        }

        void displayer::up() {

        }
    }
}
