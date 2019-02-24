//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT_STATE_CONTEXT_H
#define HISTA_PROJECT_STATE_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace hista {
    namespace state {
        struct context {
            explicit context(sf::RenderWindow &window);

            sf::RenderWindow *window;
        };
    }
}


#endif //HISTA_PROJECT_STATE_CONTEXT_H
