#pragma once
#include "raylib.h"
#include "Constantes.h"
#include "Jugador.h"
#include "Proyectil.h"

class Juego {

private:

    Jugador jugador;
    
    Proyectil* proyectil = nullptr;

    void Inicializar() {

        jugador = Jugador();

    }

    void ActualizarJuego() {

        jugador.Actualizar();

        if (proyectil != nullptr) {

            proyectil->Actualizar();

            if (proyectil->ImpactaCon(jugador.ObtRectangulo()))
                proyectil->ReboteEnJugador(jugador.ObtRectangulo());

            if (!proyectil->Activo()) {

                delete proyectil;
                proyectil = nullptr;

            }

        }

    }

    void DibujarJuego() {

        jugador.Dibujar();
        if (proyectil != nullptr) proyectil->Dibujar();

    }

public:

    Juego() {

        NuevoProyectil();

    }

    ~Juego() {

        delete proyectil;

    }

    void Actualizar() {

        ActualizarJuego();

    }

    void Dibujar() {

        BeginDrawing();
        ClearBackground(BLACK);
        DibujarJuego();
        EndDrawing();

    }

    void NuevoProyectil() {

        Rectangle rectJugador = jugador.ObtRectangulo();
        float apertura = (float)GetRandomValue(-50, 50);
        proyectil = new Proyectil(rectJugador.x + rectJugador.width / 2, rectJugador.y - radioProyectil - 1, apertura);
        return;

    }

};