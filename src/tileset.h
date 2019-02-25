#ifndef HISTA_PROJECT_TILESET_H
#define HISTA_PROJECT_TILESET_H

#include <map>
#include <memory>
#include <fstream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "resource/holder.h"
#include "resource/identifier.h"

namespace hista {
    class tileset {
    public:
        struct item {
            explicit item(unsigned int x, unsigned int y) : _x(x), _y(y) {}

            unsigned int _x;
            unsigned int _y;
        };

    public:
        tileset(std::unique_ptr<resource::texture::holder> &&holder,
                std::unique_ptr<std::map<std::string, std::shared_ptr<item>>> &&items,
                unsigned int size_x, unsigned int size_y,
                double coef_x, double coef_y);

        const sf::Texture &resource() const;

        sf::Sprite &get(const std::string &identifier);

    private:
        unsigned int tile_size_x;
        unsigned int tile_size_y;
        double coef_x;
        double coef_y;

        std::unique_ptr<std::map<std::string, std::shared_ptr<item>>> _items;
        std::unique_ptr<resource::texture::holder> _holder;

        sf::Sprite sprite;
    };

    std::unique_ptr<tileset> make_tileset(const std::string &filename, unsigned int x, unsigned int y);
}


#endif //HISTA_PROJECT_TILESET_H
