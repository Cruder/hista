#ifndef HISTA_PROJECT_MOVABLE_H
#define HISTA_PROJECT_MOVABLE_H

namespace hista {
    class movable {
    public:
        virtual void left() = 0;
        virtual void down() = 0;
        virtual void right() = 0;
        virtual void up() = 0;
    };
}

#endif //HISTA_PROJECT_MOVABLE_H
