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
#include <math.h>

namespace hista {
    namespace player {
    class displayer : public sf::Transformable, private sf::NonCopyable  {
        public:
            displayer();

        public:
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            void refreshPosition(const context &position, actions action) ;
    private:
            sf::Sprite* _sprite;
            sf::Texture _texture;
            std::map<actions,std::vector<sf::Sprite>> _animations;
            unsigned short _animationID;
            bool _isDirectionLeft;
            double animationDuration;


        };
    }
}

#endif //HISTA_PROJECT_DISPLAYER_H
