#ifndef HISTA_PROJECT_CONTEXT_ENEMY_H
#define HISTA_PROJECT_CONTEXT_ENEMY_H

namespace hista {
    namespace ennemi {
        class context_enemy {
        public:
            context_enemy(unsigned int x, unsigned int y) : _x { x }, _y { y } {
            }

        public:
            unsigned int _x;
            unsigned int _y;
        };
    }
}

#endif //HISTA_PROJECT_ENNEMI_CONTEXT_H
