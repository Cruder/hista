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
            unsigned int size_y,
            double coef_x,
            double coef_y)
            : _holder { std::move(holder) },
              _items { std::move(items) },
              tile_size_x { size_x },
              tile_size_y { size_y },
              coef_x { coef_x },
              coef_y { coef_y },
              sprite {} {
        std::cerr << "Coef " << coef_x << ' ' << coef_y << std::endl;
        sprite.setTexture(resource());
    }

    const sf::Texture &tileset::resource() const {
        return _holder->get(resource::texture::ID::Tileset);
    }

    sf::Sprite &tileset::get(const std::string &identifier) {
        std::cerr << "Tileset get " << identifier << std::endl;
        auto item = _items->find(identifier)->second;
        std::cerr << "Tileset get " << item->_x << '+' << item->_y << std::endl;
        sprite.setTextureRect(sf::IntRect(item->_x, item->_y, tile_size_x, tile_size_y));
//        sprite.scale(coef_x, coef_y);
        return sprite;
    }

    std::unique_ptr<tileset> make_tileset(const std::string& filename, unsigned int size_x, unsigned int size_y) {
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
            std::cerr << "Tileset insert " << id << std::endl;
            items->insert(std::make_pair(id, std::make_shared<hista::tileset::item>(rel_x, rel_y)));
        }

        double coef_x = size_x * 1.0 / x * 1.0;
        double coef_y = size_y * 1.0 / y * 1.0;

        return std::make_unique<tileset>(std::move(holder), std::move(items), x, y, coef_x, coef_y);
    }
}
