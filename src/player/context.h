#ifndef HISTA_PROJECT_CONTEXT_H
#define HISTA_PROJECT_CONTEXT_H

namespace hista {
    namespace player {
        class context {
        public:
            context(unsigned int x, unsigned int y) : _x { x }, _y { y } {
            }

        private:
            int _x;
            int _y;
    }
}

#endif //HISTA_PROJECT_CONTEXT_H
