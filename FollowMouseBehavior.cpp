#include "FollowMouseBehavior.h"
#include "Agent.h"
#include "raymath.h"

FollowMouseBehavior::FollowMouseBehavior() {

}

FollowMouseBehavior::~FollowMouseBehavior() {

}

void FollowMouseBehavior::update(Agent* agent, float deltaTime) {
    Vector2 mousePosition = GetMousePosition();

    Vector2 direction = Vector2Subtract(mousePosition, agent->getPosition());
    agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed * deltaTime));
}