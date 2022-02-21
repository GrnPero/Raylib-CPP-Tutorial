#pragma once

#include "raylib.h"
#include <list>

class IBehavior;

class Agent {
public:
    float _maxSpeed {50.0f};
    Vector2 _acceleration;
    Vector2 _velocity;

    Agent();
    Agent(Vector2 pos, float radius, Color color);

    virtual ~Agent() {};

    // Update the Agent and its behaviors
    virtual void update(float deltaTime);

    // Draw the agent
    virtual void draw();

    void setPosition(Vector2 pos);
    Vector2 getPosition();

    void addBehavior(IBehavior* behavior);

private:
    Vector2 _position {0.0f, 0.0f};
    float _radius {5.0f};
    Color _color {BLUE};

    std::list<IBehavior*> _behaviors;
};