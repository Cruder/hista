#include "level1.h"

namespace hista {
    namespace state {
        level1::level1(stack &stack, context ctx) : game(stack, ctx, make_level("../assets/meta/level/1.hista")) {
        }
    }
}
