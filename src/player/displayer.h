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

namespace hista {
    namespace player {
    class displayer : public sf::Drawable, public sf::Transformable, private sf::NonCopyable, public hista::Movable  {
        public:
            displayer(player::context context, const sf::Texture &texture);

        public:
            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            void left() override;

        void down() override;

        void up() override;

        void right() override;

    private:
            context _context;
            sf::Sprite _sprite;
            sf::Texture _texture;
        };
    }
}

#endif //HISTA_PROJECT_DISPLAYER_H
