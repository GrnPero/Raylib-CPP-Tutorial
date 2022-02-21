#include "SeekBehavior.h"
#include "Agent.h"
#include "raymath.h"

SeekBehavior::SeekBehavior(Agent *target) :
    _target (target) 
{

}

SeekBehavior::~SeekBehavior() {

}

void SeekBehavior::update(Agent *agent, float deltaTime) {
    Vector2 direction = Vector2Subtract(_target->getPosition(), agent->getPosition());
    agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed * deltaTime));
}