#include "component.h"

namespace hista {
    namespace gui {
        component::component() : _selected { false }, _active { false } {
        }

        component::~component() = default;
    }
}
