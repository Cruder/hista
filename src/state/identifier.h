#ifndef STATE_IDENTIFIER_H
#define STATE_IDENTIFIER_H

namespace hista {
    namespace state {
        enum class ID {
            None,
            Menu,
            Game1,
            Game2,
            Pause,
            Win,
            Lose
        };
    }
}

#endif // STATE_IDENTIFIER_H
