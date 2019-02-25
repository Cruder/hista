#ifndef HISTA_PROJECT_PLAYER_CONTEXT_H
#define HISTA_PROJECT_PLAYER_CONTEXT_H

namespace hista {
    namespace player {
        class context {
        public:
            context(unsigned int x, unsigned int y) : _x{x}, _y{y} {
            }

        public:
            unsigned int _x;
            unsigned int _y;
        };
    }
}

#endif //HISTA_PROJECT_PLAYER_CONTEXT_H
