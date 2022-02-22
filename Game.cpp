#include "Game.h"
#include "raylib.h"

Game::Game() {

}

Game::~Game() {

}

bool Game::initialise() {
    SetTargetFPS(60);
    InitWindow(800, 600, "My First Game!");

    player = new Agent({150, 150}, 20.0f, BLUE);

    followMouseBehavior = new FollowMouseBehavior();
    player->addBehavior(followMouseBehavior);
    player->_maxSpeed = 100.0f;

    redEnemy = new Agent({760, 20}, 20.0f, RED);
    seekBehavior = new SeekBehavior(player);
    redEnemy->addBehavior(seekBehavior);

    shyEnemy = new Agent({400,300}, 20.0f, YELLOW);
    fleeBehavior = new FleeBehavior(player);
    shyEnemy->addBehavior(fleeBehavior);
}

void Game::runLoop() {
    while (!WindowShouldClose()) {
        processInput();
        updateGame(GetFrameTime());
        generateOutput();
    }
}

void Game::shutDown() {
    CloseWindow();
}

void Game::generateOutput() {
    BeginDrawing();

    // Clears the screen
    ClearBackground(BLACK);

    player->draw();
    redEnemy->draw();
    shyEnemy->draw();

    EndDrawing();
}

void Game::processInput() {
    //_mousePosition = GetMousePosition();
}

void Game::updateGame(float deltaTime) {
    player->update(deltaTime);
    redEnemy->update(deltaTime);
    shyEnemy->update(deltaTime);
}