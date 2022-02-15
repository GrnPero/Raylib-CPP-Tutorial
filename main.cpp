/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main() {
    InitWindow(800, 600, "My First Game!");

    Vector2 ballPosition = { 400.0f, 300.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        // Clears the screen and makes it black
        ClearBackground(BLACK);

        // Grabs the position of the mouse
        Vector2 mousePosition = GetMousePosition();

        ballPosition = mousePosition;

        DrawCircleV(ballPosition, 20.0f, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}