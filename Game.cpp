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

    // Draw Here!

    // Draw the ball based on mouse position
    //DrawCircleV(_ballPosition, 20.0f, BLUE);
    player->draw();

    EndDrawing();
}

void Game::processInput() {
    _mousePosition = GetMousePosition();
}

void Game::updateGame(float deltaTime) {
    //_ballPosition = _mousePosition;
    player->setPosition(_mousePosition);
    player->update(deltaTime);
}