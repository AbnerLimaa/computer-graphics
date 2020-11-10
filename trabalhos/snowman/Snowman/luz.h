#ifndef LUZ_H
#define LUZ_H

#include "vetor.h"
#include "ponto.h"

class Luz
{
    private:
        Vetor c;
        Ponto f;

    public:
        Luz();
        Luz(Vetor cor, Ponto fonte);
        Vetor getCor();
        Ponto getFonte();
};

#endif // LUZ_H
