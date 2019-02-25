//
// Created by necros on 25/02/19.
//

#ifndef HISTA_PROJECT_LEVEL1_H
#define HISTA_PROJECT_LEVEL1_H


#include "game.h"

namespace hista {
    namespace state {
        class level1 : public game {
        public:
            level1(stack &stack, context ctx);
        };
    }
}

#endif //HISTA_PROJECT_LEVEL1_H
