//
// Created by necros on 20/02/19.
//

#include <iostream>
#include "tileset.h"

namespace hista {
    tileset::tileset(
            std::unique_ptr<resource::texture::holder>&& holder,
            std::unique_ptr<std::map<std::string, std::shared_ptr<item>>>&& items,
            unsigned int size_x,
            unsigned int size_y)
            : _holder { std::move(holder) },
              _items { std::move(items) },
              tile_size_x { size_x },
              tile_size_y { size_y },
              sprite {} {
        sprite.setTexture(resource());
    }

    const sf::Texture &tileset::resource() const {
        return _holder->get(resource::texture::ID::Tileset);
    }

    sf::Sprite &tileset::get(const std::string &identifier) {
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

        return sprite;
    }

    std::unique_ptr<tileset> make_tileset(const std::string& filename) {
        auto file = std::ifstream(filename);
        std::string image_name;
        std::getline(file, image_name);
        std::cerr << "Filename => " << image_name << std::endl;
        auto holder = std::make_unique<resource::texture::holder>();
        holder->load(resource::texture::ID::Tileset, image_name);
        unsigned int x, y, count;
        file >> x >> y;
        file >> count;

        auto items = std::make_unique<std::map<std::string, std::shared_ptr<tileset::item>>>();
        for(std::size_t i = 0; i < count; ++i) {
            std::string id;
            unsigned int rel_x, rel_y;
            file >> id >> rel_x >> rel_y;
            items->insert(std::make_pair(id, std::make_shared<hista::tileset::item>(rel_x, rel_y)));
        }
        return std::make_unique<tileset>(std::move(holder), std::move(items), x, y);
    }
}
