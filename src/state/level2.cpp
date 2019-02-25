#include "level2.h"

namespace hista {
    namespace state {
        level2::level2(stack &stack, context ctx) : game(stack, ctx, make_level("../assets/meta/level/2.hista")) {
        }
    }
}
