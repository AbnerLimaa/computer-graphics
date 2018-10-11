#ifndef VETOR_H
#define VETOR_H

class Vetor
{
    private:
        float x, y, z;

    public:
        Vetor();
        Vetor(float a, float b, float c);
        float getX();
        float getY();
        float getZ();
        float produtoEscalar(Vetor vetor);
        Vetor produtoVetorial(Vetor vetor);
        Vetor somar(Vetor vetor);
        Vetor subtrair(Vetor vetor);
        Vetor multiplicar(float k);
        Vetor dividir(float k);
        float norma();
        Vetor normalizar();
};

#endif // VETOR_H
