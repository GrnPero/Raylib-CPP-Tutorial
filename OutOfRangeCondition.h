#include "Condition.h"
#include "raymath.h"
#include "raylib.h"
#include "Agent.h"

class OutOfRangeCondition : public Condition
{
public:
    OutOfRangeCondition(Agent* target, float range) : _target(target), _range(range) {}
    virtual ~OutOfRangeCondition() {}
    bool Test(Agent* agent) const override
    {
        // Get the distance to the player
        float distance = Vector2Distance(_target->getPosition(), agent->getPosition());

        // Check if within range and return true/false
        return distance > _range;
    }

private:
    Agent* _target;
    float _range;
};