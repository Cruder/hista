#ifndef HISTA_PROJECT_DISPLAYER_H
#define HISTA_PROJECT_DISPLAYER_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "context.h"
#include "../behavior/Movable.h"
#include "playerUpdater.h"
#include "actions.h"
#include <iostream>

namespace hista {
    namespace player {
    class displayer : public sf::Transformable, private sf::NonCopyable  {
        public:
            displayer();

        public:
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void refreshPosition(const context &position, actions action) {
                setPosition(position._x,position._y);
                switch (action){
                    case actions::MOVE_LEFT:
                        setScale(2,2);
                        std::cout << "left" << std::endl;
                        _animationID = static_cast<unsigned short>((_animationID + 1) % _animations[action].size());
                        break;
                    case actions::MOVE_RIGHT:
                        setScale(-2,2);
                        _animationID = static_cast<unsigned short>((_animationID + 1) % _animations[action].size());
                        std::cout << "right" << std::endl;
                        break;
                    default:
                        _animationID=0;
                }
                _sprite = &_animations[action][_animationID];
            }
    private:
            sf::Sprite* _sprite;
            sf::Texture _texture;
            std::map<actions,std::vector<sf::Sprite>> _animations;
            unsigned short _animationID;


        };
    }
}

#endif //HISTA_PROJECT_DISPLAYER_H
