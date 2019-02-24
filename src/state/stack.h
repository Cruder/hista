#ifndef STATE_STACK_H
#define STATE_STACK_H

#include <vector>
#include <utility>
#include <functional>
#include <map>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include "identifier.h"
#include "base.h"

namespace sf {
    class Event;

    class RenderWindow;
}

namespace hista {
    namespace state {
        class base;

        class stack : private sf::NonCopyable {
        public:
            explicit stack(context ctx);

        public:
            enum class actions {
                Push,
                Pop,
                Clear
            };

        public:
            void update(sf::Time dt);

            void handle_event(const sf::Event &event);

            void draw();

            void push_state(ID state_id);

            void pop_state();

            void clear_states();

            bool empty() const;

            template<typename T>
            void register_state(ID state_id);

            base* create_state(ID state_id);

            bool empty();

        private:
            std::vector<base*> _stack;
            context _ctx;
            std::map<state::ID, std::unique_ptr<hista::state::base>> _factories;
        };

        template<typename T>
        void stack::register_state(ID state_id) {
            _factories[state_id] = std::make_unique<T>(*this, _ctx);
        }
    }
}

#endif // STATE_STACK_H
