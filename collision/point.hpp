#pragma once

#include "collision.hpp"

class PointCollision : public CollisionStrategy 
{
public:
    bool check(const Vec2& pPos, const Vec2&, const Vec2& rPos, const Vec2& rSize) override 
    {
        return pPos.x >= rPos.x && pPos.x <= rPos.x + rSize.x &&
            pPos.y >= rPos.y && pPos.y <= rPos.y + rSize.y;
    }
};