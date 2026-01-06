#pragma once

enum class GameEvent 
{
    EnemyDestroyed,
    PlayerDamaged,
    WallHit
};

// 5. OBSERVER
class EventHandler 
{
public:
    virtual void onEvent(GameEvent e) = 0;
    virtual ~EventHandler() = default;
};