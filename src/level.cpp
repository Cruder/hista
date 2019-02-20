#include <SFML/Graphics/Sprite.hpp>
#include "level.h"

#include <iostream>

namespace hista {
    void level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        _tilemap->draw(target, states, *_tileset);
    }

    level::level(std::unique_ptr<tilemap> tilemap, std::unique_ptr<tileset> tileset) : _tilemap { std::move(tilemap) }, _tileset { std::move(tileset) } {

    }

    std::unique_ptr<level> make_level(const std::string& filename) {
        auto file = std::ifstream(filename);
        std::string file_content;
        std::getline(file, file_content);
        std::cerr << file_content << std::endl;
        auto tilemap = make_tilemap(file_content);
        std::getline(file, file_content);
        std::cerr << file_content << std::endl;
        auto tileset = make_tileset(file_content);
        return std::make_unique<level>(std::move(tilemap), std::move(tileset));
    }
}
