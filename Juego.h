#pragma once
#include "raylib.h"
#include "Constantes.h"
#include "Jugador.h"
#include "Proyectil.h"
#include "Bloque.h"
#include "Bloque1HP.h"
#include "Bloque3HP.h"
#include "BloqueIndest.h"

const char* const Nivel1[filasBloques] = {

    "1331111331",
    "1111001111",
    "3311111133",
    "0111111110",
    "1111111111"

};

class Juego {

private:

    Jugador jugador;
    
    Proyectil* proyectil = nullptr;
    Bloque* bloques[maxBloques];
    int puntaje;

    void Inicializar() {

        jugador = Jugador();

    }

    void CreacionNivel() {

        float anchoTotal = columBloques * anchoBloque + (columBloques - 1) * distEntreBloques;
        float xInicial = (anchoP - anchoTotal) / 2;
        float yInicial = 60;

        for (int fila = 0; fila < filasBloques; fila++) {

            for (int colum = 0; colum < columBloques; colum++) {

                float xBloque = xInicial + colum * (anchoBloque + distEntreBloques);
                float yBloque = yInicial + fila * (altoBloque + distEntreBloques);
                int i = fila * columBloques + colum;

                switch (Nivel1[fila][colum]) {

                    case '1': bloques[i] = new Bloque1HP(xBloque, yBloque); 
                    break;
                    case '3': bloques[i] = new Bloque3HP(xBloque, yBloque);
                    break;
                    case '0': bloques[i] = new BloqueIndest(xBloque, yBloque);
                    break;
                    default: bloques[i] = nullptr;
                    break;
                     
                }

            }

        }

    }

    void ImpactoProyConBloques() {

        for (int i = 0; i < maxBloques; i++) {

            if (bloques[i] == nullptr) continue;
            if (!proyectil->ImpactaCon(bloques[i]->ObtRectangulo())) continue;

            proyectil->ReboteEnBloque(bloques[i]->ObtRectangulo());
            bloques[i]->EsImpactado();

            if (!bloques[i]->Activo()) {

                puntaje += bloques[i]->ObtPuntos();
                delete bloques[i];
                bloques[i] = nullptr;

            }

            return;

        }

    }

    void ActualizarJuego() {

        jugador.Actualizar();

        if (proyectil != nullptr) {

            proyectil->Actualizar();

            if (proyectil->ImpactaCon(jugador.ObtRectangulo()))
                proyectil->ReboteEnJugador(jugador.ObtRectangulo());

            ImpactoProyConBloques();

            if (!proyectil->Activo()) {

                delete proyectil;
                proyectil = nullptr;

            }

        }

    }

    void DibujarJuego() {

        jugador.Dibujar();
        if (proyectil != nullptr) proyectil->Dibujar();
        for (int i = 0; i < maxBloques; i++)
            if (bloques[i] != nullptr) bloques[i]->Dibujar();
        DrawText(TextFormat("Puntos: %d", puntaje), 10, 10, 20, WHITE);

    }

public:

    Juego() {

        for (int i = 0; i < maxBloques; i++) bloques[i] = nullptr;
        puntaje = 0;
        CreacionNivel();
        NuevoProyectil();

    }

    ~Juego() {

        delete proyectil;
        for (int i = 0; i < maxBloques; i++) delete bloques[i];

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