#ifndef JANELA_H
#define JANELA_H


class Janela
{
    private:
        float a, l, d;

    public:
        Janela();
        Janela(float altura, float largura, float distancia);
        float getAltura();
        float getLargura();
        float getDistancia();
};

#endif // JANELA_H
