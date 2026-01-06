#pragma once

#include "collision.hpp"

class AABBCollision : public CollisionStrategy 
{
public:
    bool check(const Vec2& aPos, const Vec2& aSize, const Vec2& bPos, const Vec2& bSize) override 
    {
        return aPos.x < bPos.x + bSize.x &&
            aPos.x + aSize.x > bPos.x &&
            aPos.y < bPos.y + bSize.y &&
            aPos.y + aSize.y > bPos.y;
    }
};