#include "playerUpdater.h"

namespace hista {
    namespace player {

        playerUpdater::playerUpdater() : _playerActions{}, _currentAction{actions::NONE} {
            _playerActions[hista::player::actions::MOVE_LEFT]=0;
            _playerActions[hista::player::actions::MOVE_RIGHT]=0;
            _playerActions[hista::player::actions::CLIMB]=0;
            _playerActions[hista::player::actions::MOVE_DOWN]=0;
        }

        void playerUpdater::update(context &position, float delta_time) {

            if(_playerActions[actions::MOVE_LEFT] > 0){
                position._x--;
                _playerActions[actions::MOVE_LEFT] -= delta_time;
            }
            else if(_playerActions[actions::MOVE_RIGHT] > 0){
                position._x++;
                _playerActions[actions::MOVE_RIGHT] -= delta_time;
            }
            else if(_playerActions[actions::CLIMB] > 0){
                position._y--;
                _playerActions[actions::CLIMB] -= delta_time;
            }
            else if(_playerActions[actions::MOVE_DOWN] > 0){
                position._y++;
                _playerActions[actions::MOVE_DOWN] -= delta_time;
            }
            resetAction();
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