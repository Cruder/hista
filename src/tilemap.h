#ifndef HISTA_PROJECT_TILEMAP_H
#define HISTA_PROJECT_TILEMAP_H

#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "tileset.h"

namespace hista {
    class tilemap {
    public:
        class layer {
        public:
            using label = std::string;
            using line = std::vector<label>;
            using map_matrix = std::vector<line>;
        public:
            layer(const map_matrix labels) : labels{labels} {}

            void draw(sf::RenderTarget &target, sf::RenderStates &states, hista::tileset &tileset) const;

        private:

            map_matrix labels;
        };

    public:
        tilemap(const std::vector<layer> &layers, const layer &collision, const layer &climbable);

        void draw(sf::RenderTarget &target, sf::RenderStates &states, hista::tileset &tileset) const;

    private:
        std::vector<layer> _layers;
        layer _collision;
        layer _climbable;
    };

    std::unique_ptr<tilemap> make_tilemap(const std::string &filename);
};

#endif //HISTA_PROJECT_TILEMAP_H
