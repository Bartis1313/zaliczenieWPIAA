#pragma once

#include "event.hpp"

namespace events
{
    class LoggingObserver : public EventHandler 
    {
        Logger& logger;
    public:
        LoggingObserver(Logger& l) 
            : logger(l) 
        {

        }

        void onEvent(GameEvent e) override 
        {
            switch (e) 
            {
            case GameEvent::EnemyDestroyed:
                logger.log("Event: Enemy destroyed");
                break;
            case GameEvent::PlayerDamaged:
                logger.log("Event: Player damaged");
                break;
            case GameEvent::WallHit:
                logger.log("Event: Wall hit");
                break;
            }
        }
    };
}