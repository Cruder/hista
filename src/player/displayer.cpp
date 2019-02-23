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
            std::vector<sf::Sprite> leftAnimation;
            std::vector<sf::Sprite> rightAnimation;
            leftAnimation.emplace_back(_texture,sf::IntRect(66,23,12,16));
            leftAnimation.emplace_back(_texture,sf::IntRect(88,24,15,16));
            leftAnimation.emplace_back(_texture,sf::IntRect(113,25,15,15));
            rightAnimation.emplace_back(_texture,sf::IntRect(66,42,12,16));
            rightAnimation.emplace_back(_texture,sf::IntRect(88,42,15,16));
            rightAnimation.emplace_back(_texture,sf::IntRect(113,42,15,15));
            _animations[actions::MOVE_LEFT] = leftAnimation;
            _animations[actions::MOVE_RIGHT] = rightAnimation;
            _animations[actions::NONE].emplace_back(leftAnimation[0]);
            _animations[actions::NONE].emplace_back(rightAnimation[0]);
            _animations[actions::MOVE_DOWN] = _animations[actions::NONE];
            _animations[actions::CLIMB] = _animations[actions::NONE];

            std::vector<sf::Sprite> _verticalAnimation;
            _isDirectionLeft= true;
            _animationID=0;
        }

        void displayer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
            states.transform *= getTransform();

            target.draw(*_sprite, states);
        }

    }

    void player::displayer::refreshPosition(const player::context &position, player::actions action) {
        setPosition(position._x,position._y);

        auto id = (_animationID+1) % (_animations[action].size());
        switch (action){
            case actions::MOVE_LEFT:
                _animationID = static_cast<unsigned short>( id );
                _isDirectionLeft= true;
                break;
            case actions::MOVE_RIGHT:
                _animationID = static_cast<unsigned short>( id );
                _isDirectionLeft= false;
                break;
            default:
                _animationID= static_cast<unsigned short>(_isDirectionLeft ? 0 : 1);
        }
        _sprite = &_animations[action][_animationID];
    }

}
