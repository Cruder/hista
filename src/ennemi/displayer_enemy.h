//
// Created by Orchestra on 18/01/2019.
//

#ifndef HISTA_PROJECT_DISPLAYER_ENEMY_H
#define HISTA_PROJECT_DISPLAYER_ENEMY_H



#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "context.h"

namespace hista {
    namespace ennemi {
        class displayer_enemy : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
        public:
            displayer_enemy(ennemi::context_enemy context);
            displayer_enemy(ennemi::context_enemy context, const sf::Texture &texture);

        public:
            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        private:
            context_enemy _context;
            sf::Sprite _sprite;
            sf::Texture _texture;
        };
    }
}


#endif //HISTA_PROJECT_DISPLAYER_H
