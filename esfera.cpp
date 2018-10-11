#include <cmath>
#include <limits>
#include "esfera.h"

Esfera::Esfera()
{

}

Esfera::Esfera(Ponto centro, float raio)
{
    this->c = centro;
    this->r = raio;
}

Ponto Esfera::getCentro()
{
    return this->c;
}

float Esfera::getRaio()
{
    return this->r;
}

bool Esfera::intercepta(Raio raio, float *t)
{
    Vetor OC = this->c.subtrair(raio.getOrigem());
    float l_maior = raio.getDirecao().produtoEscalar(OC);
    if(l_maior < 0)
        return false;
    float d = sqrtf(OC.produtoEscalar(OC) - (l_maior * l_maior));
    if(d < 0 || d > this->r)
        return false;
    float l_interno = sqrtf((this->r * this->r) - (d * d));
    float t1 = l_maior - l_interno;
    float t2 = l_maior + l_interno;
    float menor;
    if(t1 < t2 && t1 >= 0)
        menor = t1;
    else if(t2 >= 0)
        menor = t2;
    else
        return false;
    *t = menor;
    return true;
}
