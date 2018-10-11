#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <QWidget>

class Programa
{
    public:
        Programa();
        void show();
        static void desenharCenario(void);
        static void setup(void);
        static void redimensionar(int w, int h);
        static void entradaTeclado(unsigned char key, int x, int y);
};

#endif // PROGRAMA_H
