#include "base.h"

namespace hista {
    namespace state {
        context base::get_context() const {
            return _ctx;
        }

        base::base(stack &stack, context ctx) : _stack{&stack}, _ctx{ctx} {
        }

        void base::request_stack_push(ID state_id) {
            _stack->push_state(state_id);
        }

        void base::request_stack_pop() {
            _stack->pop_state();
        }

        void base::request_state_clear() {
            _stack->clear_states();
        }
    }
}
