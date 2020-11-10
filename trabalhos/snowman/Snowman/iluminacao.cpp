#include <cmath>
#include "iluminacao.h"
#include "vetor.h"

Iluminacao::Iluminacao()
{

}

Vetor Iluminacao::calcularIluminacao(Ponto ponto, Ponto origem, Vetor normal, Luz luz, Material material)
{
    Vetor l = luz.getFonte().subtrair(ponto).normalizar();
    Vetor ambiente, difusa, especular;

    ambiente = material.getAmbiente();

    float produto_escalar_difusa = normal.produtoEscalar(l);
    float cosseno_difusa = produto_escalar_difusa / (normal.norma() * l.norma());
    Vetor k_difusa = material.getDifusa().multiplicar(produto_escalar_difusa / cosseno_difusa);
    difusa = luz.getCor().produtoArroba(k_difusa);

    Vetor r, v;
    v = origem.subtrair(ponto).normalizar();
    r = normal.multiplicar(2 * produto_escalar_difusa).subtrair(l);
    float produto_escalar_especular = v.produtoEscalar(r);
    float cosseno_especular = produto_escalar_especular / (r.norma() * v.norma());
    float m = material.getReflexividade();
    Vetor k_especular = material.getEspecular().multiplicar(pow(produto_escalar_especular, m) / cosseno_especular);
    especular = luz.getCor().produtoArroba(k_especular);

    Vetor cor = difusa.somar(especular).somar(ambiente);
    return cor;
}
