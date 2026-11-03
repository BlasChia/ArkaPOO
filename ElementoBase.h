#pragma once
#include "raylib.h"

class ElementoBase {

protected:

    float x, y;
    float ancho, alto;
    bool activo;

public:

    ElementoBase(float x, float y, float ancho, float alto) : x(x), y(y), ancho(ancho), alto(alto), activo(true) {

    }

    virtual ~ElementoBase() {

    }

    virtual void Actualizar() = 0;
    virtual void Dibujar() = 0;

    Rectangle ObtRectangulo() {

        return {x, y, ancho, alto};

    }

    bool Activo() const {

        return activo;

    }

    void Desactivar() {

        activo = false;

    }

};