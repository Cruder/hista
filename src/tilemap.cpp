#include <iostream>
#include "tilemap.h"

namespace hista {
    tilemap::tilemap(const std::vector<tilemap::layer> &layers, const layer &collision, const layer &climbable)
            : _layers{layers}, _collision{collision}, _climbable{climbable} {
    }

    void tilemap::draw(sf::RenderTarget &target, sf::RenderStates &states, tileset &tileset) const {
        for (const auto &layer : _layers) {
            layer.draw(target, states, tileset);
        }
    }

    void tilemap::layer::draw(sf::RenderTarget &target, sf::RenderStates &states, hista::tileset &tileset) const {
        int acc_y = 0;
        for (const auto &line : labels) {
            int acc_x = 0;
            for (const auto &label : line) {
                acc_x += 16;
                if (label != "0") {
                    auto sprite = tileset.get(label);
                    target.draw(sprite, states);
                }
                states.transform.translate(sf::Vector2f(16.0f, 0.0f));
            }
            acc_y += 16;
            states.transform.translate(-acc_x, 16.0f);
        }
        states.transform.translate(0, -acc_y);
    }

    tilemap::layer internal__make_layer(std::ifstream &file, unsigned int x, unsigned int y) {
        auto labels = tilemap::layer::map_matrix{};
        labels.reserve(x);
        for (std::size_t i = 0; i < x; ++i) {
            tilemap::layer::line line{};
            line.reserve(y);
            for (std::size_t j = 0; j < y; ++j) {
                std::string label;
                file >> label;
                line.push_back(label);
            }
            labels.push_back(line);
        }

        return tilemap::layer(labels);
    }

    std::unique_ptr<tilemap> make_tilemap(const std::string &filename) {
        auto file = std::ifstream(filename);
        unsigned int x, y, count;
        file >> x >> y;
        file >> count;

        std::vector<tilemap::layer> layers;
        layers.reserve(count);
        for (std::size_t i = 0; i < count; ++i) {
            layers.push_back(internal__make_layer(file, x, y));
        }

        return std::make_unique<tilemap>(layers, internal__make_layer(file, x, y), internal__make_layer(file, x, y));
    }
}
