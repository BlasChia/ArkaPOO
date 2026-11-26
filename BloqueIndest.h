#pragma once
#include "Bloque.h"

class BloqueIndest : public Bloque {

    protected:

        Color ObtColor() const override {

            return GRAY;

        }

    public:

        BloqueIndest(float x, float y) : Bloque(x, y, 0, false) {
            
        }

        void EsImpactado() override {

        }

        bool EsDestructible() {

            return false;

        }

};