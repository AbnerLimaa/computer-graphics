#ifndef PONTO_H
#define PONTO_H

#include "vetor.h"

class Ponto
{
    private:
        float x, y, z;

    public:
        Ponto();
        Ponto(float a, float b, float c);
        float getX();
        float getY();
        float getZ();
        Ponto somar(Vetor vetor);
        Vetor subtrair(Ponto ponto);
};

#endif // PONTO_H
