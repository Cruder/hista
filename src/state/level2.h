//
// Created by necros on 25/02/19.
//

#ifndef HISTA_PROJECT_LEVEL2_H
#define HISTA_PROJECT_LEVEL2_H

#include "game.h"

namespace hista {
    namespace state {
        class level2 : public game {
        public:
            level2(stack &stack, context ctx);
        };
    }
}

#endif //HISTA_PROJECT_LEVEL2_H
