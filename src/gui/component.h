#ifndef HISTA_PROJECT_COMPONENT_H
#define HISTA_PROJECT_COMPONENT_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <memory>


namespace sf {
    class Event;
}

namespace hista {
    namespace gui {
        class component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
        public:
            component();

            ~component() override;

            inline void select() { _selected = true; }

            inline void deselect() { _selected = false; }

            inline void activate() { _active = true; }

            inline void deactivate() { _active = false; }

            virtual void handle_event(const sf::Event &event) = 0;

        private:
            bool _selected;
            bool _active;
        };
    }
}

#endif //HISTA_PROJECT_COMPONENT_H
