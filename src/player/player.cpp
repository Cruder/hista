#include "player.h"

namespace hista{
    namespace player{

        player::player(context position) :
            _position{position},
            _updater{},
            _displayer{},
            _currentAction(actions::NONE),
            _animations {entity::make_animation("../assets/meta/animations/mario.hista")}
        {
//            _displayer.refreshPosition(_position,_currentAction);
        }

        void player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//            _displayer.draw(target, states);
            _animations->setPosition(_position._x,_position._y);
            _animations->setScale(2.f,2.f);

            _animations->draw(target,states);
        }

        void player::startMovement(actions action,float timeInit) {
            _updater.startMovement(action, timeInit);
        }

        void player::update(sf::Time delta_time) {
            _currentAction = _updater.update(_position, delta_time);
            _displayer.refreshPosition(_position,_currentAction);
            _animations->update(delta_time);
        }
    }
}
