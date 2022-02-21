#pragma once

#include "raylib.h"

class Agent;

class IBehavior {
public:
    // Empty Constructor and Destructor for the base class
    IBehavior() {}
    ~IBehavior() {}

    // Pure Virtual Functions for executing the Behavior
    virtual void update(Agent* agent, float deltaTime) = 0;
};