//
// Created by Orchestra on 18/01/2019.
//

#include "displayer_enemy.h"
namespace hista {
    namespace ennemi {
        displayer_enemy::displayer_enemy(ennemi::context_enemy context) : _context { context } {
            _texture.loadFromFile("../assets/images/textures.png");
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(256, 56, 40, 32));
            _sprite.setScale(2,2);
            setPosition(context._x, context._y);
        }

        displayer_enemy::displayer_enemy(ennemi::context_enemy context, const sf::Texture &texture) : _context { context }, _texture {texture} {
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(256, 56, 40, 32));
            _sprite.setScale(2,2);
            setPosition(context._x, context._y);
        }

        void displayer_enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();
            target.draw(_sprite, states);
        }


    }
}
