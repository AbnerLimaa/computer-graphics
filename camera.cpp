#include "camera.h"
#include "programa.h"

Camera::Camera()
{
    this->o = Ponto();
}

Camera::Camera(Ponto origem, Ponto ponto)
{
    this->o = origem;
    //this->janela = Janela(Programa::altura, Programa::largura, this->o.getZ() + 100);
    this->janela = Janela(2, 2, 0);
    lookAt(ponto);
}

Ponto Camera::getOrigem()
{
    return this->o;
}

void Camera::lookAt(Ponto ponto)
{
    Vetor temp = Vetor(0, 1, 0);
    Vetor direcao = ponto.subtrair(this->o);
    this->k = direcao.multiplicar(-1).normalizar();
    this->j = temp.produtoVetorial(this->k);
    this->i = this->k.produtoVetorial(this->j);
}

Raio Camera::lancarRaio(Ponto ponto, int altura, int largura)
{
    float x = (ponto.getX() * this->janela.getLargura()) / largura;
    float y = (ponto.getY() * this->janela.getAltura()) / altura;
    float z = this->janela.getDistancia();
    Ponto novoPonto = Ponto(x, y, z);
    Vetor direcao = novoPonto.subtrair(this->o).normalizar();
    return Raio(this->o, direcao);
}
