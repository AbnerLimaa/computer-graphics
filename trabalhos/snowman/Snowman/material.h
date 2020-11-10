#ifndef MATERIAL_H
#define MATERIAL_H

#include "vetor.h"

class Material
{
    private:
        Vetor k_ambiente;
        Vetor k_difusa;
        Vetor k_especular;
        float r;

    public:
        Material();
        Material(Vetor ambiente, Vetor difusa, Vetor especular, float reflexividade);
        Vetor getAmbiente();
        Vetor getDifusa();
        Vetor getEspecular();
        float getReflexividade();
};

#endif // MATERIAL_H
