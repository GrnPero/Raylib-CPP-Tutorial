#include "raylib.h"
#include "Agent.h"

class Game {
public:
    Game();
    ~Game();
    // Init the game
    bool initialise();
    // Runs the game loop
    void runLoop();
    // Closes the game
    void shutDown();
private:
    // Position of the ball object
    Vector2 _ballPosition = { 0.0f, 0.0f };
    Vector2 _mousePosition = { 0.0f, 0.0f };

    Agent* player;

    // Helper functions for the loop
    void processInput();
    void updateGame(float deltaTime);
    void generateOutput();
};