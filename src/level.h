#ifndef HISTA_PROJECT_LEVEL_H
#define HISTA_PROJECT_LEVEL_H

#include "tilemap.h"

namespace hista {
    class level : public sf::Drawable, public sf::Transformable {
    public:
        level(std::unique_ptr<tilemap> tilemap, std::unique_ptr<tileset> tileset);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        std::unique_ptr<tilemap> _tilemap;
        std::unique_ptr<tileset> _tileset;

        unsigned int tile_size_x;
        unsigned int tile_size_y;
    };

    std::unique_ptr<level> make_level(const std::string& filename);
}

#endif //HISTA_PROJECT_LEVEL_H
