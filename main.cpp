#include "raylib.h"
#include "Constantes.h"

int main() {

    InitWindow(anchoP, altoP, "TP Final - ArkaPOO - Blas Ignacio Chiapero");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Prueba Ventana", 190, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}