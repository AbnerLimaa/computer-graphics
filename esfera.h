#ifndef ESFERA_H
#define ESFERA_H

#include "ponto.h"
#include "raio.h"

class Esfera
{
    private:
        Ponto c;
        float r;

    public:
        Esfera();
        Esfera(Ponto centro, float raio);
        Ponto getCentro();
        float getRaio();
        bool intercepta(Raio raio, float *t);
};

#endif // ESFERA_H
