#include "player.h"

namespace hista{
    namespace player{

        player::player(context position) : _position{position}, _updater{}, _displayer{} {
            _displayer.refreshPosition(_position);
        }

        void player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            _displayer.draw(target, states);
        }

        void player::startMovement(actions action,float timeInit) {
            _updater.startMovement(action, timeInit);
        }

        void player::update(float delta_time) {
            _updater.update(_position, delta_time);
            _displayer.refreshPosition(_position);
        }

    }
}