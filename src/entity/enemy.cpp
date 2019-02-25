//
// Created by necros on 24/02/19.
//

#include <iostream>
#include "enemy.h"


namespace hista {
    namespace entity {
        static const std::map<std::string, enemy::direction> mapper{
                {"left",  enemy::direction::Left},
                {"right", enemy::direction::Right}
        };

        enemy::direction string_to_direction(const std::string &dir) {
            return mapper.find(dir)->second;
        }

        enemy::action::action(unsigned int threshold, const std::string &direction, const std::string &animation) :
                threshold{threshold}, direction{string_to_direction(direction)}, local_animation{animation},
                elapsed_time{0} {
        }

        void enemy::action::assign_enemy(enemy *enemy) {
            self = enemy;
        }

        std::optional<sf::Time> enemy::action::update(sf::Time dt) {
            elapsed_time += dt.asMilliseconds();

            float coef;

            switch (direction) {
                case direction::Left:
                    coef = -1.0f;
                    break;
                case direction::Right:
                    coef = 1.0f;
                    break;
                default:
                    coef = 0.0f;
            }

            self->move(sf::Vector2f(coef * dt.asSeconds() * 15, 0.0f));

            if (elapsed_time > threshold) {
                auto tmp = elapsed_time;
                elapsed_time = 0;
                return std::optional<sf::Time>{sf::milliseconds(tmp - threshold)};
            } else {
                return std::nullopt;
            }
        }

        const std::string &enemy::action::animation() const {
            return local_animation;
        }

        void enemy::update(sf::Time dt) {
            animation->set_animation(actions[current_action]->animation());
            animation->update(dt);

            while (auto remain = actions[current_action]->update(dt)) {
                dt -= *remain;
                current_action = (current_action + 1) % (unsigned int) actions.size();
                animation->set_animation(actions[current_action]->animation());
            }
        }

        enemy::enemy(sf::Vector2f position, std::unique_ptr<hista::entity::animation> &&animation) :
                entity{position}, animation{std::move(animation)}, actions{}, current_action{0} {
        }

        void enemy::move(sf::Vector2f delta) {
            position += delta;
        }

        void enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform.translate(position);
            target.draw(*animation, states);
        }

        void enemy::add_action(std::unique_ptr<action> &&action) {
            action->assign_enemy(this);
            actions.push_back(std::move(action));
        }

        std::unique_ptr<enemy> make_enemy(const std::string &filename, sf::Vector2f position) {
            auto file = std::ifstream(filename);
            std::string animation_name;
            std::getline(file, animation_name);

            unsigned int count;
            file >> count;

            auto enemy = std::make_unique<hista::entity::enemy>(position, make_animation(animation_name));

            for (std::size_t i = 0; i < count; ++i) {
                unsigned int threshold;
                std::string direction, animation;

                file >> threshold >> direction >> animation;

                auto action = std::make_unique<enemy::action>(threshold, direction, animation);

                enemy->add_action(std::move(action));
            }

            return std::move(enemy);
        }
    }
}
