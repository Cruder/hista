#ifndef STATE_STATE_H
#define STATE_STATE_H

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "identifier.h"
#include "context.h"
#include "stack.h"

namespace sf {
    class RenderWindow;
}

namespace hista {
    namespace state {
        class stack;

        class base {
        public:
            using ptr = std::unique_ptr<base>;

        public:
            base(stack &stack, context ctx);
            virtual ~base() {};

            virtual void draw() = 0;

            virtual bool update(sf::Time dt) = 0;

            virtual bool handle_event(const sf::Event &event) = 0;

        protected:
            void request_stack_push(ID state_id);

            void request_stack_pop();

            void request_state_clear();

            context get_context() const;

        protected:
            stack *_stack;
            context _ctx;
        };
    }
}

#endif // STATE_STATE_H
