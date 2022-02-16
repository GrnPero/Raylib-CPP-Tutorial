#include "Agent.h"

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

}

void Agent::draw() {
    // Draws the ball for the agent with the values of the position
    DrawCircleV(_position, _radius, _color);
}