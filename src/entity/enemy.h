//
// Created by necros on 24/02/19.
//

#ifndef HISTA_PROJECT_ENEMY_H
#define HISTA_PROJECT_ENEMY_H

#include "entity.h"
#include "animation.h"
#include <memory>
#include <optional>

namespace hista {
    namespace entity {
        class enemy : public entity {
        public:
            enum class direction {
                Left,
                Right
            };

        public:
            class action : sf::NonCopyable {
            public:
                action(unsigned int threshold, const std::string &direction, const std::string &animation);

                void assign_enemy(enemy *enemy);

                std::optional<sf::Time> update(sf::Time dt);

                const std::string &animation() const;

            public:
            private:
                const unsigned int threshold;
                unsigned int elapsed_time;
                const std::string local_animation;

                direction direction;

                enemy *self;
            };

        public:
            enemy(sf::Vector2f position, std::unique_ptr<animation> &&animation);

            void update(sf::Time dt) override;

            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

            void move(sf::Vector2f delta);

            void add_action(std::unique_ptr<action> &&action);

        private:
            std::unique_ptr<animation> animation;
            std::vector<std::unique_ptr<action>> actions;
            unsigned int current_action;
        };

        std::unique_ptr<enemy> make_enemy(const std::string &filename, sf::Vector2f position);
    }
}

#endif //HISTA_PROJECT_ENEMY_H
