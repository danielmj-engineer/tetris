/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
    // Tell the window to use vsync and work on high DPI displays
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Create the window and OpenGL context
    InitWindow(1920, 1080, "Tetris");

    // Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
    SearchAndSetResourceDir("resources");

    // Load a texture from the resources directory
    Texture bp_image = LoadTexture("cat.png");
    // image from https://www.loc.gov/resource/cph.3g08217/. Public domain

    // game loop
    while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
    {
        // drawing
        BeginDrawing();

        // Setup the back buffer for drawing (clear color and depth buffers)
        ClearBackground(BLACK);

        // draw some text using the default font
        DrawText("Tetris clone", 200,200,20,WHITE);

        // draw our texture to the screen
        DrawTexture(bp_image, 400, 200, WHITE);

        // end the frame and get ready for the next one  (display frame, poll input, etc...)
        EndDrawing();
    }

    // cleanup
    // unload our texture so it can be cleaned up
    UnloadTexture(bp_image);

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
    return 0;
}
