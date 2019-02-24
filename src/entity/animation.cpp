//
// Created by necros on 24/02/19.
//

#include <iostream>
#include "animation.h"

namespace hista {
    namespace entity {
        animation::animation(std::unique_ptr<std::map<std::string, std::unique_ptr<action>>>&& actions,
                             std::shared_ptr<sf::Texture>&& image,
                             const std::string &current_action) :
                             actions { std::move(actions) },
                             image { std::move(image) },
                             current_action { current_action } {
        }

        void animation::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            auto action = actions->find(current_action)->second.get();

            target.draw(action->current_sprite());
        }

        void animation::update(const sf::Time &delta_time) {
            auto action = actions->find(current_action)->second.get();

            action->update(delta_time);
        }

        animation::action::action(const std::weak_ptr<sf::Texture>& image, unsigned int count, unsigned int x, unsigned int y,
                                  unsigned int threshold, unsigned int width, unsigned int height) :
                                  image { image }, frame_count { count },
                                  x_start { x }, y_start { y },
                                  threshold_ms { threshold },
                                  elapsed_time { 0 }, current_frame { 0 },
                                  width { width }, height { height } {
            sprite.setTexture(*image.lock());
        }

        void animation::action::next_frame() {
            current_frame = (current_frame + 1) % frame_count;
        }

        sf::Sprite& animation::action::current_sprite() {
//            std::cerr << "Current sprite => " << x_start << " " << width * current_frame << std::endl;
//            std::cerr << "current_frame => " << current_frame << std::endl;
//            std::cerr << width << ' ' << height << std::endl;
            sprite.setTextureRect(sf::IntRect(x_start + width * current_frame, y_start, width, height));

            return sprite;
        }

        void animation::action::update(const sf::Time& delta_time) {
//            std::cerr << "Elapsed time => " << elapsed_time;
            elapsed_time += delta_time.asMilliseconds();
//            std::cerr << " -> " << elapsed_time << std::endl;
//            std::cerr << threshold_ms << std::endl;

            while(elapsed_time > threshold_ms) {
                elapsed_time -= threshold_ms;
                next_frame();
            }
        }

        std::unique_ptr<animation> make_animation(const std::string &filename) {
            {
                auto file = std::ifstream(filename);
                std::string image_name;
                std::getline(file, image_name);

                auto texture = std::make_shared<sf::Texture>();
                texture->loadFromFile(image_name);

                unsigned int x, y, count;
                file >> x >> y;
                file >> count;

                auto actions = std::make_unique<std::map<std::string, std::unique_ptr<animation::action>>>();
                for(std::size_t i = 0; i < count; ++i) {
                    std::string name;
                    unsigned int frame_count, start_x, start_y, threshold;

                    file >> name >> frame_count >> start_x >> start_y >> threshold;

//                    std::cerr << "name " << name << " frame_count " << frame_count << " start_x " << start_x << " start_y " << start_y << " threshold " << threshold << std::endl;

                    auto action = std::make_unique<animation::action>(std::weak_ptr(texture), frame_count, start_x, start_y, threshold, x, y);
                    actions->insert(std::pair(name, std::move(action)));
                }

                return std::make_unique<animation>(std::move(actions), std::move(texture), "move");
            }
        }
    }
}
