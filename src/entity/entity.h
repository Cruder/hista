//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT_ENTITY_H
#define HISTA_PROJECT_ENTITY_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

namespace hista {
    namespace entity {
        class entity : public sf::Drawable, public sf::Transformable, public sf::NonCopyable {
        public:
            explicit entity(const sf::Vector2f position) : position{position} {}

            virtual void update(sf::Time dt) = 0;

        protected:
            sf::Vector2f position;
        };
    }
}

#endif //HISTA_PROJECT_ENTITY_H
