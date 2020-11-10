#ifndef ILUMINACAO_H
#define ILUMINACAO_H

#include "vetor.h"
#include "luz.h"
#include "material.h"

class Iluminacao
{
    public:
        Iluminacao();
        static Vetor calcularIluminacao(Ponto ponto, Ponto origem, Vetor normal, Luz luz, Material material);
};

#endif // ILUMINACAO_H
