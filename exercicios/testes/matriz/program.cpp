#include <stdio.h>
#include "matriz.h"

int main(int argc, char** argv)
{
    Matriz m1(3, 3);
    Matriz m2(3, 1);
    /**m1.inserir(0, 0, 2);
    m1.inserir(0, 1, 4);
    m1.inserir(0, 2, 1);
    m1.inserir(1, 0, -5);
    m1.inserir(1, 1, 7);
    m1.inserir(1, 2, 10);
    m1.inserir(2, 0, 0);
    m1.inserir(2, 1, 6);
    m1.inserir(2, 2, 0);**/

    m1.inserir(0, 0, 1);
    m1.inserir(0, 1, 0);
    m1.inserir(0, 2, 0);
    m1.inserir(1, 0, 0);
    m1.inserir(1, 1, 1);
    m1.inserir(1, 2, 0);
    m1.inserir(2, 0, 0);
    m1.inserir(2, 1, 0);
    m1.inserir(2, 2, 1);

    m2.inserir(0, 0, 4);
    m2.inserir(1, 0, 1);
    m2.inserir(2, 0, 3);

    Matriz r = m1.multiplicar(m2);
    int** resultado = r.getMatriz();
    for(int i = 0; i < r.getLinhas(); i++)
    {
        for(int j = 0; j < r.getColunas(); j++)
            printf("%d\t", resultado[i][j]);
        printf("\n");
    }
    return 0;
}