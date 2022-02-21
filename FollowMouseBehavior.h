#pragma once

#include "raylib.h"
#include "IBehavior.h"

class Agent;

class FollowMouseBehavior : public IBehavior {
public:
    FollowMouseBehavior();
    ~FollowMouseBehavior();

    virtual void update(Agent* agent, float deltaTime);
private:
    Agent* _target;
};