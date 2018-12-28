//
// Created by necros on 28/12/18.
//

#ifndef HISTA_PROJECT_STATE_H
#define HISTA_PROJECT_STATE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "resource/identifier.h"

namespace hista {
    namespace states {
        class stack {

        };
    }

    namespace states {
        class component {
        public:
            struct context {
                context(sf::RenderWindow& window, resource::texture::holder& textures, resource::font::holder& fonts);

                sf::RenderWindow* window;
                resource::texture::holder* textures;
                resource::font::holder* fonts;
            };

        public:
            component(states::stack& stack, context context);

            inline context export_context() const { return _context; }
        private:
            stack* _stack;
            context _context;
        };
    }
}

#endif //HISTA_PROJECT_STATE_H
