#include "raio.h"

Raio::Raio()
{

}

Raio::Raio(Ponto origem, Vetor direcao)
{
    this->o = origem;
    this->d = direcao;
}

Ponto Raio::getOrigem()
{
    return this->o;
}

Vetor Raio::getDirecao()
{
    return this->d;
}
