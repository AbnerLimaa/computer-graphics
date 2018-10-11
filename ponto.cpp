#include "ponto.h"

Ponto::Ponto()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Ponto::Ponto(float a, float b, float c)
{
    this->x = a;
    this->y = b;
    this->z = c;
}

float Ponto::getX()
{
    return this->x;
}

float Ponto::getY()
{
    return this->y;
}

float Ponto::getZ()
{
    return this->z;
}

Ponto Ponto::somar(Vetor vetor)
{
    return Ponto(this->x + vetor.getX(), this->y + vetor.getY(), this->z + vetor.getZ());
}

Vetor Ponto::subtrair(Ponto ponto)
{
    return Vetor(this->x - ponto.getX(), this->y - ponto.getY(), this->z - ponto.getZ());
}
