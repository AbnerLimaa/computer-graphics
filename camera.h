#ifndef CAMERA_H
#define CAMERA_H

#include "vetor.h"
#include "ponto.h"
#include "raio.h"
#include "janela.h"

class Camera
{
    private:
        Vetor i, j, k;
        Ponto o;
        Janela janela;

    public:
        Camera();
        Camera(Ponto ponto);
        void lookAt(Ponto ponto);
        Raio lancarRaio(Ponto ponto, int altura, int largura);
};

#endif // CAMERA_H
