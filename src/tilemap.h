#ifndef HISTA_PROJECT_STATE_H
#define HISTA_PROJECT_STATE_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include "platforms/context.h"

namespace hista {
    class tilemap {
    private:
        tilemap(const sf::Texture &texture) : _texture { texture };

    private:
        sf::Texture _texture;
        std::vector<platforms::context> platform_contexts;
    };
}
