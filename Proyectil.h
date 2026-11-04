#pragma once
#include <cmath>
#include "ElementoBase.h"
#include "Constantes.h"

class Proyectil : public ElementoBase {

private:

    float rProy, velX, velY;

public:

    Proyectil(float spawnX, float spawnY, float angulo) : ElementoBase(spawnX - radioProyectil, spawnY - radioProyectil, radioProyectil * 2, radioProyectil * 2), rProy(radioProyectil) {

        float rad = angulo * DEG2RAD;
        velX = velProyectil * sinf(rad);
        velY = -velProyectil * cosf(rad);

    }

    Vector2 ObtCentro() const {

        return {

            x + rProy, y + rProy

        };

    }

    void Actualizar() override {

        float deltaT = GetFrameTime();
        x += velX * deltaT;
        y += velY * deltaT;

        if (x < 0) {

            x = 0;
            velX = -velX;

        }

        if (x + ancho > anchoP) {

            x = anchoP - ancho;
            velX = -velX;

        }

        if (y < 0) {

            y = 0;
            velY = -velY;

        }

        if (y > altoP) Desactivar();

    }

    void Dibujar() override {

        DrawCircleV(ObtCentro(), rProy, WHITE);

    }

    bool ImpactaCon(Rectangle rect) const { 
    
        return CheckCollisionCircleRec(ObtCentro(), rProy, rect);

    }

    void ReboteEnJugador(Rectangle jugador) {

        if (velY < 0) return;

        float centroJugador = jugador.x + jugador.width / 2;
        float apertura = (ObtCentro().x - centroJugador) / (jugador.width / 2);
        if (apertura < -1) apertura = -1;
        if (apertura > 1) apertura = 1;

        float rad = apertura * 60 * DEG2RAD;
        velX = velProyectil * sinf(rad);
        velY = -velProyectil * cosf(rad);
        y = jugador.y - alto;

    }

    void ReboteEnBloque(Rectangle bloque) {

        Vector2 cBloque = ObtCentro();
        float rebIzq = (cBloque.x + rProy) - bloque.x;
        float rebDer = (bloque.x + bloque.width) - (cBloque.x - rProy);
        float rebSup = (cBloque.y + rProy) - bloque.y;
        float rebInf = (bloque.y + bloque.height) - (cBloque.y - rProy);

        float xMin = rebDer;
        if (rebIzq < rebDer) xMin = rebIzq;

        float yMin = rebInf;
        if (rebSup < rebInf) yMin = rebSup;

        if (xMin < yMin) {

            if (rebIzq < rebDer) {

                if (velX > 0) velX = -velX;
                x-= rebIzq;

            } else {

                if (velX < 0) velX = -velX;
                x += rebDer;

            }

        } else {

            if (rebSup < rebInf) {

                if (velY > 0) velY = -velY;
                y -= rebSup;

            } else {

                if (velY < 0) velY = -velY;
                y += rebInf;

            }

        }

    }

};