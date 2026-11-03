#pragma once
#include "raylib.h"
#include "Constantes.h"
#include "Jugador.h"

class Juego {

private:

    Jugador jugador;

    void Inicializar() {

        jugador = Jugador();

    }

    void ActualizarJuego() {

        jugador.Actualizar();

    }

    void DibujarJuego() {

        jugador.Dibujar();

    }

public:

    void Actualizar() {

        ActualizarJuego();

    }

    void Dibujar() {

        BeginDrawing();
        ClearBackground(BLACK);
        DibujarJuego();
        EndDrawing();

    }

};