#include "luz.h"
#include "vetor.h"
#include "ponto.h"

Luz::Luz()
{
    Vetor branco(1, 1, 1);
    this->c = branco;
    this->f = Ponto();
}

Luz::Luz(Vetor cor, Ponto fonte)
{
    this->c = cor;
    this->f = fonte;
}

Vetor Luz::getCor()
{
    return this->c;
}

Ponto Luz::getFonte()
{
    return this->f;
}
