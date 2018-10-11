#include <cmath>
#include "vetor.h"

Vetor::Vetor()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vetor::Vetor(float a, float b, float c)
{
    this->x = a;
    this->y = b;
    this->z = c;
}

float Vetor::getX()
{
    return this->x;
}

float Vetor::getY()
{
    return this->y;
}

float Vetor::getZ()
{
    return this->z;
}

float Vetor::produtoEscalar(Vetor vetor)
{
    return (this->x * vetor.getX()) + (this->y * vetor.getY()) + (this->z * vetor.getZ());
}

Vetor Vetor::produtoVetorial(Vetor vetor)
{
    float x = (this->y * vetor.getZ()) - (this->z * vetor.getY());
    float y = (this->z * vetor.getX()) - (this->x * vetor.getZ());
    float z = (this->x * vetor.getY()) - (this->y * vetor.getX());
    return Vetor(x, y, z);
}

Vetor Vetor::somar(Vetor vetor)
{
    return Vetor(this->x + vetor.getX(), this->y + vetor.getY(), this->z + vetor.getZ());
}

Vetor Vetor::subtrair(Vetor vetor)
{
    return Vetor(this->x - vetor.getX(), this->y - vetor.getY(), this->z - vetor.getZ());
}

Vetor Vetor::multiplicar(float k)
{
    return Vetor(this->x * k, this->y * k, this->z * k);
}

Vetor Vetor::dividir(float k)
{
    float c = 1 / k;
    return Vetor(this->x * c, this->y * c, this->z * c);
}

float Vetor::norma()
{
    return sqrtf(produtoEscalar(*this));
}

Vetor Vetor::normalizar()
{
    return dividir(norma());
}
