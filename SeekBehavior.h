#pragma once

#include "raylib.h"
#include "IBehavior.h"
class Agent;

class SeekBehavior : public IBehavior {
public:
    SeekBehavior(Agent* target);
    ~SeekBehavior();

    virtual void update(Agent* agent, float deltaTime);
private:
    Agent* _target;
};