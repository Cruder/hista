#include "player_updater.h"

namespace hista {
    namespace player {

        playerUpdater::playerUpdater() : _playerActions{}, _currentAction{actions::NONE} {
            _playerActions[hista::player::actions::MOVE_LEFT]=0;
            _playerActions[hista::player::actions::MOVE_RIGHT]=0;
            _playerActions[hista::player::actions::CLIMB]=0;
            _playerActions[hista::player::actions::MOVE_DOWN]=0;
        }

        actions playerUpdater::update(context &position, sf::Time delta_time) {

            if(_playerActions[actions::MOVE_LEFT] > 0){
                position._x--;
                _playerActions[actions::MOVE_LEFT] -= delta_time.asSeconds();
            }
            else if(_playerActions[actions::MOVE_RIGHT] > 0){
                position._x++;
                _playerActions[actions::MOVE_RIGHT] -= delta_time.asSeconds();
            }
            else if(_playerActions[actions::CLIMB] > 0){
                position._y--;
                _playerActions[actions::CLIMB] -= delta_time.asSeconds();
            }
            else if(_playerActions[actions::MOVE_DOWN] > 0){
                position._y++;
                _playerActions[actions::MOVE_DOWN] -= delta_time.asSeconds();
            }
            resetAction();
            return _currentAction;
        }

        void playerUpdater::resetAction() {
            if( _playerActions[actions::MOVE_LEFT] <= 0
             && _playerActions[actions::MOVE_RIGHT] <= 0
             && _playerActions[actions::CLIMB] <= 0
             && _playerActions[actions::MOVE_DOWN] <= 0)
                _currentAction=actions::NONE;
        }

        void playerUpdater::startMovement(const hista::player::actions &action, float timeInit) {
            resetAction();
            if(_currentAction==actions::NONE){
                _currentAction=action;
                _playerActions[action]=timeInit;
            }
        }
    }
}