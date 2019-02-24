#include "stack.h"

namespace hista {
    namespace state {
        stack::stack(context ctx) : _ctx{ctx} {

        }

        void stack::update(sf::Time dt) {
            // Iterate from top to bottom, stop as soon as update() returns false
            for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr) {
                if (!(*itr)->update(dt))
                    break;
            }
        }

        void stack::handle_event(const sf::Event &event) {
            // Iterate from top to bottom, stop as soon as handleEvent() returns false
            for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr) {
                if (!(*itr)->handle_event(event))
                    break;
            }
        }

        void stack::draw() {
            // Draw all active states from bottom to top
            for (base::ptr &state : _stack) {
                state->draw();
            }
        }

        bool stack::empty() const {
            return _stack.empty();
        }

        void stack::push_state(ID state_id) {
            _stack.push_back(create_state(state_id));
        }

        void stack::pop_state() {
            _stack.pop_back();
        }

        void stack::clear_states() {
            _stack.clear();
        }

        std::unique_ptr<base> stack::create_state(ID state_id) {
            return std::move(_factories[state_id]);
        }
    }
}
