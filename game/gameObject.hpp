#pragma once

#include "../event/event.hpp"
#include "../state/idle.hpp"
#include "../math/vec.hpp"
#include "../collision/collision.hpp"

class GameObject 
{
protected:
    Vec2 pos{ };
    Vec2 size{ };
    std::unique_ptr<ObjectState> state;
    std::vector<EventHandler*> observers;
public:
    GameObject(float x, float y, float w, float h) : 
        pos{ x, y }, size{ w, h }, state{ std::make_unique<IdleState>() } 
    {

    }

    void attach(EventHandler* o) { observers.push_back(o); }
    void notify(GameEvent e) { for (auto o : observers) o->onEvent(e); }

    virtual void accept(CollisionVisitor&) = 0;

    Vec2 getPos() const { return pos; }
    Vec2 getSize() const { return size; }

    void setState(std::unique_ptr<ObjectState> s) { state = std::move(s); }
    const char* getStateName() const { return state->getType().name(); }
    virtual ~GameObject() = default;

    ADD_TYPEINFO;
};


class Player : public GameObject 
{
public:
    Player(float x, float y) : 
        GameObject{ x, y, 2, 2 }
    {

    }
    void accept(CollisionVisitor& v) override { v.visit(*this); }
};

class Wall : public GameObject 
{
public:
    Wall(float x, float y, float w, float h) : 
        GameObject{ x, y, w, h } 
    {

    }
    void accept(CollisionVisitor& v) override { v.visit(*this); }
};