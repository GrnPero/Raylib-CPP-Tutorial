#pragma once

#include "raylib.h"
#include "IBehavior.h"

class FleeBehavior : public IBehavior {
public:
    FleeBehavior(Agent* target);
    ~FleeBehavior();

    virtual void update(Agent* agent, float deltaTime);
private:
    Agent* _target;
};