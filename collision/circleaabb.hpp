#pragma once

#include "collision.hpp"

#include <algorithm>

class CircleAABBCollision : public CollisionStrategy 
{
public:
    bool check(const Vec2& cPos, const Vec2& cSize, const Vec2& rPos, const Vec2& rSize) override 
    {
        float closestX = std::clamp(cPos.x, rPos.x, rPos.x + rSize.x);
        float closestY = std::clamp(cPos.y, rPos.y, rPos.y + rSize.y);
        float dx = cPos.x - closestX;
        float dy = cPos.y - closestY;
        return (dx * dx + dy * dy) <= (cSize.x * cSize.x);
    }
};