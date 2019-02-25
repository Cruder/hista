#ifndef HISTA_PROJECT_CONTAINER_H
#define HISTA_PROJECT_CONTAINER_H

#include <memory>
#include <vector>
#include <optional>
#include "component.h"

namespace hista {
    namespace gui {
        class container : public component {
        public:
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        private:
            void select(unsigned int index);

        private:
            std::vector<std::shared_ptr<component>> _children;
            std::optional<unsigned int> _selected_child;
        };
    }
}

#endif //HISTA_PROJECT_CONTAINER_H
