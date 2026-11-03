#pragma once
#include "ElementoBase.h"
#include "Constantes.h"

class Jugador : public ElementoBase {

private:

    float velJugador;

public:

    Jugador() : ElementoBase(anchoP / 2.0f - 50, altoP - 40, 100, 15), velJugador(450) {

    }

    void Actualizar() override {

        float deltaT = GetFrameTime();
        if (IsKeyDown(KEY_A)) x -= velJugador * deltaT;
        if (IsKeyDown(KEY_D)) x += velJugador * deltaT;

        if (x < 0) x = 0;
        if (x + ancho > anchoP) x = anchoP - ancho;

    }

    void Dibujar() override {

        DrawRectangle((int)x, (int)y, (int)ancho, (int)alto, BLUE);

    }

};