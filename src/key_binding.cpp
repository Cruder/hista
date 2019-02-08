#include "key_binding.h"

namespace hista {
    const key_binding::mapper key_binding::DIRECTIONAL_KEYS = {
            { sf::Keyboard::Left, player::actions::MOVE_LEFT },
            { sf::Keyboard::Right, player::actions::MOVE_RIGHT },
            { sf::Keyboard::Down, player::actions::MOVE_DOWN},
            { sf::Keyboard::Up, player::actions::CLIMB},
//            { sf::Keyboard::Up, player::actions::JUMP},
    };

    const key_binding::mapper key_binding::QWEASD_KEYS {
            { sf::Keyboard::A, player::actions::MOVE_LEFT },
            { sf::Keyboard::D, player::actions::MOVE_RIGHT },
            { sf::Keyboard::W, player::actions::JUMP },
    };

    const key_binding::mapper key_binding::AZEQSD_KEYS {
            { sf::Keyboard::Q, player::actions::MOVE_LEFT },
            { sf::Keyboard::D, player::actions::MOVE_RIGHT },
            { sf::Keyboard::Z, player::actions::JUMP },
    };

    key_binding::key_binding(const key_binding::mapper &keys) : _keys { keys } {
    }

    std::vector<player::actions> key_binding::actions() {
        std::vector<player::actions> action_list {};

        for(const auto &[key, value] : _keys) {
            if(sf::Keyboard::isKeyPressed(key)) {
                action_list.push_back(value);
            }
        }

        return action_list;
    }
}
