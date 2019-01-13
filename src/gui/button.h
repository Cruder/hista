#ifndef HISTA_PROJECT_BUTTON_H
#define HISTA_PROJECT_BUTTON_H

#include "component.h"

namespace hista {
    namespace gui {
        class button : public component {
        public:
            button() : component() {};

        private:
            enum class actions {
                Push,
                Pop,
                Clear
            };
        };
    }
}

#endif //HISTA_PROJECT_BUTTON_H
