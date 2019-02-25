

#ifndef HISTA_PROJECT_MARIO_H
#define HISTA_PROJECT_MARIO_H

#include "entity.h"
#include "animation.h"
#include <memory>
#include <optional>

namespace hista {
    namespace entity {
        class mario : public entity {
        public:
            enum class direction {
                LEFT,
                RIGHT,
                CLIMB,
                DOWN,
                JUMP,
                IDLE_LEFT,
                IDLE_RIGHT
            };

        public:
            mario(sf::Vector2f position, std::unique_ptr<animation> &&animation);

            void update(sf::Time dt) override;

            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

            void move(sf::Vector2f delta);

            void start_movement(direction direction1);

        private:
            void reset();

        private:
            direction _current_action;
            float _elapsed_time;
            std::unique_ptr<animation> _animation;
        };

        std::unique_ptr<mario> make_mario(const std::string &filename, sf::Vector2f position);
    }
}

#endif //HISTA_PROJECT_MARIO_H
