#include "displayer.h"

namespace hista {
    namespace player {
        displayer::displayer() {
            _texture.loadFromFile("../assets/images/textures.png");
//            _sprite.setTexture(_texture);
//            _sprite.setTextureRect(sf::IntRect(66, 23, 12, 16));
//            _sprite.setTextureRect(sf::IntRect(89, 23, 15, 16));
//            _sprite.setTextureRect(sf::IntRect(113, 25, 15, 16));
//            _sprite.setTextureRect(sf::IntRect(137, 23, 13, 16));
            setScale(2, 2);
            std::vector<sf::Sprite> horizontalAnimation;
            horizontalAnimation.emplace_back(_texture,sf::IntRect(66,23,12,16));
            horizontalAnimation.emplace_back(_texture,sf::IntRect(88,24,15,16));
            horizontalAnimation.emplace_back(_texture,sf::IntRect(113,25,15,15));
            _animations[actions::MOVE_LEFT] = horizontalAnimation;
            _animations[actions::MOVE_RIGHT] = horizontalAnimation;
            _animations[actions::NONE] = std::vector(&_animations[actions::MOVE_LEFT][0],&_animations[actions::MOVE_LEFT][1]);

            std::vector<sf::Sprite> _verticalAnimation;

            _animationID=0;
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
            states.transform *= getTransform();
//            sf::Sprite sp = _animations.at()[0];
            target.draw(*_sprite, states);
        }

    }
}
