#include "Game.h"
#include "raylib.h"

Game::Game() {

}

Game::~Game() {

}

bool Game::initialise() {
    SetTargetFPS(60);
    InitWindow(800, 600, "My First Game!");
}

void Game::runLoop() {
    while (!WindowShouldClose()) {
        processInput();
        updateGame();
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
    DrawCircleV(_ballPosition, 20.0f, BLUE);

    EndDrawing();
}

void Game::processInput() {
    _mousePosition = GetMousePosition();
}

void Game::updateGame() {
    _ballPosition = _mousePosition;
}