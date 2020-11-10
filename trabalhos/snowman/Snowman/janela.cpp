#include "janela.h"

Janela::Janela()
{
    this->a = 0;
    this->l = 0;
    this->d = 0;
}

Janela::Janela(float altura, float largura, float distancia)
{
    this->a = altura;
    this->l = largura;
    this->d = distancia;
}

float Janela::getAltura()
{
    return this->a;
}

float Janela::getLargura()
{
    return this->l;
}

float Janela::getDistancia()
{
    return this->d;
}
