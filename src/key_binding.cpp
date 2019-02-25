#include "key_binding.h"

namespace hista {
    const key_binding::mapper key_binding::DIRECTIONAL_KEYS = {
            { sf::Keyboard::Left, entity::mario::direction::LEFT },
            { sf::Keyboard::Right, entity::mario::direction::RIGHT },
            { sf::Keyboard::Down, entity::mario::direction::DOWN},
            { sf::Keyboard::Up, entity::mario::direction::CLIMB},
//            { sf::Keyboard::Up, entity::mario::direction::JUMP},
    };

    const key_binding::mapper key_binding::QWEASD_KEYS {
            { sf::Keyboard::A, entity::mario::direction::LEFT },
            { sf::Keyboard::D, entity::mario::direction::RIGHT },
            { sf::Keyboard::W, entity::mario::direction::JUMP },
    };

    const key_binding::mapper key_binding::AZEQSD_KEYS {
            { sf::Keyboard::Q, entity::mario::direction::LEFT },
            { sf::Keyboard::D, entity::mario::direction::RIGHT },
            { sf::Keyboard::Z, entity::mario::direction::JUMP },
    };

    key_binding::key_binding(const key_binding::mapper &keys) : _keys { keys } {
    }

    std::vector<entity::mario::direction> key_binding::actions() {
        std::vector<entity::mario::direction> action_list {};

        for(const auto &[key, value] : _keys) {
            if(sf::Keyboard::isKeyPressed(key)) {
                action_list.push_back(value);
            }
        }

        return action_list;
    }
}
