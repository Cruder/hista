
#include <iostream>
#include "mario.h"

namespace hista {
    namespace entity {

        void mario::update(sf::Time dt) {
            _animation->update(dt);

            if(_elapsed_time>0) {
                _elapsed_time-=dt.asMilliseconds();
                switch (_currentAction) {
                    case direction::LEFT:
                        position.x += -1 * dt.asSeconds() * 15;
                        break;
                    case direction::RIGHT:
                        position.x += 1 * dt.asSeconds() * 15;
                        break;
                    case direction::CLIMB:
                        position.y += -1 * dt.asSeconds() * 15;
                        break;
                    case direction::DOWN:
                        position.y += 1 * dt.asSeconds() * 15;
                    default:
                        break;
                }


            } else
                reset();
        }

        void mario::reset() {
            if(_currentAction==direction::LEFT) {
                _currentAction=direction::IDLE_LEFT;
                _animation->set_animation("idle_left");
            }
            else if(_currentAction==direction::RIGHT) {
                _currentAction = direction::IDLE_RIGHT;
                _animation->set_animation("idle_right");
            }
        }

        void mario::startMovement(mario::direction direction1) {
            std::string newAnimation;
            _currentAction = direction1;
            switch (_currentAction){
                case direction::LEFT:
                    newAnimation="move_left";
                    break;
                case direction::RIGHT:
                    newAnimation="move_right";
                    break;
                default:
                    newAnimation="idle_left";

            }
            _elapsed_time=300;
            _animation->set_animation(newAnimation);
        }

        mario::mario(sf::Vector2f position, std::unique_ptr<hista::entity::animation> &&animation) :
                entity{position}, _animation{std::move(animation)} {
        }

        void mario::move(sf::Vector2f delta) {
            position += delta;
        }

        void mario::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform.translate(position);
            states.transform.scale(2.f,2.f);
            target.draw(*_animation, states);
        }


        std::unique_ptr<mario> make_mario(const std::string &filename, sf::Vector2f position) {
            std::cerr << filename << std::endl;
            auto file = std::ifstream(filename);
            std::string animation_name;
            std::getline(file, animation_name);
            std::cerr << animation_name << std::endl;

            unsigned int count;
            file >> count;

            auto mario = std::make_unique<hista::entity::mario>(position, make_animation(animation_name));
//
//            std::cerr << "animation done" << std::endl;
//            for(std::size_t i = 0; i < count; ++i) {
//                unsigned int threshold;
//                std::string direction, animation;
//
//                file >> threshold >> direction >> animation;
//
//                auto action = std::make_unique<mario::action>(threshold, direction, animation);
//
//                mario->add_action(std::move(action));
//            }

            return std::move(mario);
        }
    }
}