#include "Agent.h"
#include "raymath.h"
#include "IBehavior.h"

Agent::Agent() {
    _position = Vector2 {0,0};
}

Agent::Agent(Vector2 pos, float radius, Color color) : 
    _position {pos},
    _radius {radius},
    _color {color} {
}

void Agent::setPosition(Vector2 pos) {
    _position = pos;
}

Vector2 Agent::getPosition() {
    return _position;
}

void Agent::update(float deltaTime) {
    // For each behavior from the bahavior list
    for (auto it = _behaviors.begin(); it != _behaviors.end(); it++) {
        (*it)->update(this, deltaTime);
    }

    _velocity.x += _acceleration.x;
    _velocity.y += _acceleration.y;

    // Check if the magnitude of the velocity
    if (Vector2Length(_velocity) > _maxSpeed) {
        _velocity = Vector2Scale(Vector2Normalize(_velocity), _maxSpeed);
    }

    _position.x += _velocity.x * deltaTime;
    _position.y += _velocity.y * deltaTime;

    _acceleration = {0.0f, 0.0f};
}

void Agent::draw() {
    // Draws the ball for the agent with the values of the position
    DrawCircleV(_position, _radius, _color);
}

void Agent::addBehavior(IBehavior* behavior) {
    _behaviors.push_back(behavior);
}