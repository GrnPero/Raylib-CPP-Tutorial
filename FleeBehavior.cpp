#include "FleeBehavior.h"
#include "Agent.h"
#include "raymath.h"

FleeBehavior::FleeBehavior(Agent* target) :
    _target (target)
{

}

FleeBehavior::~FleeBehavior() {

}

void FleeBehavior::update(Agent* agent, float deltaTime) {
    float distance = Vector2Distance(_target->getPosition(), agent->getPosition());

    // Flees when target is too close
    if (distance < 125.0f) {
        Vector2 direction = Vector2Subtract(agent->getPosition(), _target->getPosition());
        agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed * deltaTime));
    } else {
        // Slows the agent down
        agent->_acceleration.x = agent->_velocity.x * deltaTime;
        agent->_acceleration.y = agent->_velocity.y * deltaTime;
    }
}