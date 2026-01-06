#include <iostream>

#include "collision/collision.hpp"
#include "state/destroyed.hpp"
#include "state/idle.hpp"
#include "game/gameObject.hpp"

// 3. VISITOR impl
class CollisionHandler : public CollisionVisitor 
{
public:
    void visit(Player& p) override 
    {
        p.setState(std::make_unique<DestroyedState>());
        p.notify(GameEvent::EnemyDestroyed);
    }
    void visit(Wall& w) override 
    {
        w.notify(GameEvent::WallHit);
    }
};

enum class ObjectType 
{ 
    Player,
    Wall 
};

// 4. FACTORY
class GameObjectFactory
{
public:
    static std::unique_ptr<GameObject> create(ObjectType type, float x, float y, float w = 2, float h = 2) 
    {
        switch (type) 
        {
            case ObjectType::Player: return std::make_unique<Player>(x, y);
            case ObjectType::Wall:   return std::make_unique<Wall>(x, y, w, h);
        }
        return nullptr;
    }
};

#include "logger/consoleLog.hpp"
#include "logger/fileLog.hpp"
#include "event/eventLogger.hpp"

#include "collision/aabb.hpp"
#include "collision/circle.hpp"
#include "collision/circleaabb.hpp"
#include "collision/point.hpp"

int main()
{
    // template, "użycie"
    auto consoleLogger = std::make_shared<ConsoleLogger>(true);
    auto fileLogger = std::make_shared<FileLogger>("game.log", true);

    // kompozyt, użycie
    CompositeLogger multiLogger;
    multiLogger.addLogger(consoleLogger);
    multiLogger.addLogger(fileLogger);

    // observer, eventhandler. Użycie
    events::LoggingObserver observer{ multiLogger };

    // factory, użycie
    auto player = GameObjectFactory::create(ObjectType::Player, 0, 0);
    auto wall = GameObjectFactory::create(ObjectType::Wall, 1, 1, 2, 2);

    // observer, eventhandler. Użycie
    player->attach(&observer);
    wall->attach(&observer);

    // strategia, użycie
    std::vector<std::unique_ptr<CollisionStrategy>> strategies;
    strategies.push_back(std::make_unique<AABBCollision>());
    strategies.push_back(std::make_unique<CircleCollision>());
    strategies.push_back(std::make_unique<CircleAABBCollision>());
    strategies.push_back(std::make_unique<PointCollision>());

    for (auto& strat : strategies) 
    {
        // strategia, użycie
        bool collided = strat->check(player->getPos(), player->getSize(), wall->getPos(), wall->getSize());
        multiLogger.log(std::format("Collision ({}) : {}", strat->getType().name(), collided ? "YES" : "NO"));

        if (collided) 
        {
            // wizytor, użycie
            CollisionHandler handler;
            player->accept(handler);
            wall->accept(handler);
        }
    }

    // wizytor, użycie
    multiLogger.log(std::format("Player state: {}", player->getStateName()));
    multiLogger.log(std::format("Wall state: {}", wall->getStateName()));

    return 0;
}