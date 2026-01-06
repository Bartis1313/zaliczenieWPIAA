#pragma once

#include "../math/vec.hpp"

// 1. STRATEGY base
class CollisionStrategy 
{
public:
    virtual bool check(const Vec2& aPos, const Vec2& aSize, const Vec2& bPos, const Vec2& bSize) = 0;
    virtual ~CollisionStrategy() = default;

    ADD_TYPEINFO;
};

class Player;
class Wall;

// 3. VISITOR
class CollisionVisitor
{
public:
    virtual void visit(Player&) = 0;
    virtual void visit(Wall&) = 0;
    virtual ~CollisionVisitor() = default;
};