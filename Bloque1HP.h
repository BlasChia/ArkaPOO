#pragma once
#include "Bloque.h"

class Bloque1HP : public Bloque {

protected:

    Color ObtColor() const override {

        return esBonus ? DARKGREEN : BLUE;

    }

public:

    Bloque1HP(float x, float y, bool esBonus = false) : Bloque(x, y, 100, esBonus) {

    }

    void EsImpactado() override {

        Desactivar();

    }

};