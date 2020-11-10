#include "material.h"
#include "vetor.h"

Material::Material()
{
    Vetor branco(1, 1, 1);
    this->k_ambiente = branco;
    this->k_difusa = branco;
    this->k_especular = branco;
    this->r = 0;
}

Material::Material(Vetor ambiente, Vetor difusa, Vetor especular, float reflexividade)
{
    this->k_ambiente = ambiente;
    this->k_difusa = difusa;
    this->k_especular = especular;
    this->r = reflexividade;
}

Vetor Material::getAmbiente()
{
    return this->k_ambiente;
}

Vetor Material::getDifusa()
{
    return this->k_difusa;
}

Vetor Material::getEspecular()
{
    return this->k_especular;
}

float Material::getReflexividade()
{
    return this->r;
}
