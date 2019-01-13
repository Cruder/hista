#ifndef HISTA_PROJECT_KEY_BINDING_H
#define HISTA_PROJECT_KEY_BINDING_H

#include <map>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include "player/actions.h"

namespace hista {
    class key_binding {
    public:
        typedef std::map<sf::Keyboard::Key, player::actions> mapper;
    public:
        static const mapper DIRECTIONAL_KEYS;
        static const mapper QWEASD_KEYS;
        static const mapper AZEQSD_KEYS;

    public:
        explicit key_binding(const mapper& keys = DIRECTIONAL_KEYS);

        std::vector<player::actions> actions();

    private:
        mapper _keys;
    };
}

#endif //HISTA_PROJECT_KEY_BINDING_H
