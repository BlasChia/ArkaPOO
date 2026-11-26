#pragma once
#include "Bloque.h"

class Bloque3HP : public Bloque {

    private:

        int vida;

    protected:

        Color ObtColor() const override {

            if (vida == 3) return RED;
            if (vida == 2) return ORANGE;
            return YELLOW;

        }

    public:

        Bloque3HP(float x, float y, bool esBonus = false) : Bloque(x, y, 300, esBonus) {

            vida = 3;

        }

        void EsImpactado() override {

            vida--;
            if (vida <= 0) Desactivar();

        }

};