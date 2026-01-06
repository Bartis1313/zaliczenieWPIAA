#pragma once

class GameObject;

// 2. STAN
class ObjectState 
{
public:
    virtual void update(GameObject& obj) = 0;
    virtual ~ObjectState() = default;

    ADD_TYPEINFO;
};