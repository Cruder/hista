#ifndef HISTA_PROJECT_PLAYER_H
#define HISTA_PROJECT_PLAYER_H

#include "context.h"
#include "../behavior/movable.h"
#include "player_updater.h"
#include "actions.h"

namespace hista{
    namespace player{
        class player : public sf::Drawable{
        public:
            player(context position);

        public:
            void update(float delta_time);
            void startMovement(actions action, float timeInit);
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        private:
            context _position;
            playerUpdater _updater;
            displayer _displayer;
            actions _currentAction;
        };
    }
}

#endif //HISTA_PROJECT_PLAYER_H
