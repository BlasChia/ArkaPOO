#include "raylib.h"
#include "Constantes.h"
#include "Juego.h"

int main() {

    InitWindow(anchoP, altoP, "TP Final - ArkaPOO - Blas Ignacio Chiapero");
    SetTargetFPS(60);

    Juego juego;

    while (!WindowShouldClose()) {
        
        juego.Actualizar();
        juego.Dibujar();

    }

    CloseWindow();
    return 0;

}