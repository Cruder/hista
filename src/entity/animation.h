//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT_ANIMATION_H
#define HISTA_PROJECT_ANIMATION_H

#include <map>
#include <memory>
#include <fstream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>

#include "../resource/holder.h"
#include "../resource/identifier.h"

namespace hista {
    namespace entity {
    class animation : public sf::Drawable {
        public:
            class action : public sf::NonCopyable, public sf::Transformable {
            public:
                explicit action(const std::weak_ptr<sf::Texture>& image, unsigned int count, unsigned int x, unsigned int y, unsigned int threshold,
                       unsigned int width, unsigned int height);

                void next_frame();
                sf::Sprite& current_sprite();

                void update(const sf::Time& delta_time);
            private:
                const unsigned int frame_count;
                const unsigned int x_start;
                const unsigned int y_start;

                const unsigned int width;
                const unsigned int height;

                const std::weak_ptr<sf::Texture> image;

                sf::Sprite sprite;

                const unsigned int threshold_ms;

                unsigned int elapsed_time;
                unsigned int current_frame;

            };
        public:
            animation(std::unique_ptr<std::map<std::string, std::unique_ptr<action>>>&& actions, std::shared_ptr<sf::Texture>&& image, const std::string& current_action);

            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            void update(const sf::Time& delta_time);
            void set_animation(const std::string& animation);


        private:
            std::string current_action;
            std::unique_ptr<std::map<std::string, std::unique_ptr<action>>> actions;

            std::shared_ptr<sf::Texture> image;
        };

        std::unique_ptr<animation> make_animation(const std::string& filename);
    }
}

#endif //HISTA_PROJECT_ANIMATION_H
