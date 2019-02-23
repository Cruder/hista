#ifndef HISTA_PROJECT_MARIOUPDATER_H
#define HISTA_PROJECT_MARIOUPDATER_H

#include <map>
#include "displayer.h"
#include "actions.h"

namespace hista {
    namespace player {
        class playerUpdater {
        public:
            playerUpdater();
        public:
            void startMovement(const hista::player::actions &action, float timeInit);
            void update(context& position, float delta_time);

        private:
            void resetAction();
        private:
            actions _currentAction;
            std::map<actions,double> _playerActions;
        };
    }
}

#endif //HISTA_PROJECT_MARIOUPDATER_H
