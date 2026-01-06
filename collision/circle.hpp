#pragma once

#include "collision.hpp"

class CircleCollision : public CollisionStrategy 
{
public:
    bool check(const Vec2& aPos, const Vec2& aSize, const Vec2& bPos, const Vec2& bSize) override 
    {
        float dx = aPos.x - bPos.x;
        float dy = aPos.y - bPos.y;
        float r = aSize.x + bSize.x;
        return (dx * dx + dy * dy) <= (r * r);
    }
};