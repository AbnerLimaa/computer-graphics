#ifndef ESFERA_H
#define ESFERA_H

#include "ponto.h"
#include "raio.h"
#include "material.h"
#include "vetor.h"

class Esfera
{
    private:
        Ponto c;
        float r;
        Material m;

    public:
        Esfera();
        Esfera(Ponto centro, float raio, Material material);
        Ponto getCentro();
        float getRaio();
        Material getMaterial();
        bool intercepta(Raio raio, float *t);
        Vetor normal(Ponto ponto);
};

#endif // ESFERA_H
