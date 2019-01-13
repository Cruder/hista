#ifndef HISTA_PROJECT_DISPLAYER_H
#define HISTA_PROJECT_DISPLAYER_H

#include "player/context.h"

namespace hista {
    namespace player {
        class displayer {
        public:
            displayer(player::context context) : _context { context } {
            }

        public:
            void draw();

        private:
            player::context _context;
    }
}

#endif //HISTA_PROJECT_DISPLAYER_H
