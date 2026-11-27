#pragma once
#include "ElementoBase.h"
#include "Constantes.h"

class Bloque : public ElementoBase {

protected:

    int puntos;
    bool esBonus;
    virtual Color ObtColor() const = 0;

public:

    Bloque(float x, float y, int puntos, bool esBonus) : ElementoBase(x, y, anchoBloque, altoBloque), puntos(puntos), esBonus(esBonus) {
        
    }

    virtual void EsImpactado() = 0;

    void Actualizar() override {

    }

    void Dibujar() override {

        Rectangle rectBloque = ObtRectangulo();
        DrawRectangleRec(rectBloque, ObtColor());
        DrawRectangleLinesEx(rectBloque, 2, GRAY);

        if (esBonus) {

            DrawRectangleLinesEx(rectBloque, 3, ORANGE);
            DrawCircle((int)(x + ancho / 2), (int)(y + alto / 2), 5, ORANGE);

        }

    }

    int ObtPuntos() const {

        return puntos;

    }

    bool EsBonus() const {

        return esBonus;

    }

    virtual bool EsDestructible() {

        return true;

    }

};