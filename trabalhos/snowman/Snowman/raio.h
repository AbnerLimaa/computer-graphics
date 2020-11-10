#ifndef RAIO_H
#define RAIO_H

#include "ponto.h"
#include "vetor.h"

class Raio
{
    private:
        Ponto o;
        Vetor d;

    public:
        Raio();
        Raio(Ponto origem, Vetor direcao);
        Ponto getOrigem();
        Vetor getDirecao();
};

#endif // RAIO_H
