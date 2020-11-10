#include <stdlib.h>
#include "matriz.h"

Matriz::Matriz(int linhas, int colunas)
{ 
    if(linhas > 0 && colunas > 0)
    {
        Matriz::n_linhas = linhas;
        Matriz::n_colunas = colunas;
        Matriz::matriz = (int**)calloc(linhas, sizeof(int*));
        for(int i = 0; i < linhas; i++)
            Matriz::matriz[i] = (int*)calloc(colunas, sizeof(int));
    }
    
}

int Matriz::getLinhas()
{
    return Matriz::n_linhas;
}

int Matriz::getColunas()
{
    return Matriz::n_colunas;
}

int** Matriz::getMatriz()
{
    return Matriz::matriz;
}

void Matriz::inserir(int linha, int coluna, int valor)
{
    if(linha >= 0 && linha < Matriz::n_linhas)
        if(coluna >= 0 && coluna < Matriz::n_colunas)
            Matriz::matriz[linha][coluna] = valor;
}

void Matriz::somar(Matriz matriz)
{
    if(matriz.n_linhas == Matriz::n_linhas && matriz.n_colunas == Matriz::n_colunas)
        for(int i = 0; i < Matriz::n_linhas; i++)
            for(int j = 0; j < Matriz::n_colunas; j++)
                Matriz::matriz[i][j] += matriz.matriz[i][j];
}

void Matriz::subtrair(Matriz matriz)
{
    if(matriz.n_linhas == Matriz::n_linhas && matriz.n_colunas == Matriz::n_colunas)
        for(int i = 0; i < Matriz::n_linhas; i++)
            for(int j = 0; j < Matriz::n_colunas; j++)
                Matriz::matriz[i][j] -= matriz.matriz[i][j];
}

void Matriz::multiplicar(int escalar)
{
    for(int i = 0; i < Matriz::n_linhas; i++)
        for(int j = 0; j < Matriz::n_colunas; j++)
            Matriz::matriz[i][j] *= escalar;
}

Matriz Matriz::multiplicar(Matriz matriz)
{
    if(Matriz::n_colunas == matriz.n_linhas)
    {
        Matriz m(Matriz::n_linhas, matriz.n_colunas);
        for(int i = 0; i < m.n_linhas; i++)
            for(int j = 0; j < m.n_colunas; j++)
            {
                int valor = 0;
                for(int p = 0; p < Matriz::n_colunas; p++)
                    for(int q = 0; q < matriz.n_linhas; q++)
                        valor += (Matriz::matriz[i][p] * matriz.matriz[q][j]);
                m.inserir(i, j, valor);
            }
        return m;
    }
}

void Matriz::transposta()
{
    int** linhas = (int**)calloc(Matriz::n_colunas, sizeof(int*));
    for(int i = 0; i < Matriz::n_colunas; i++)
        linhas[i] = (int*)calloc(Matriz::n_linhas, sizeof(int));
    for(int i = 0; i < Matriz::n_linhas; i++)
        for(int j = 0; j < Matriz::n_colunas; j++)
            linhas[j][i] = Matriz::matriz[i][j];
    for(int i = 0; i < Matriz::n_linhas; i++)
        free(Matriz::matriz[i]);
    free(Matriz::matriz);
    Matriz::matriz = linhas;
    int aux = Matriz::n_linhas;
    Matriz::n_linhas = Matriz::n_colunas;
    Matriz::n_colunas = aux;
}