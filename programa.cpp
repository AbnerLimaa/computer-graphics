#include <float.h>
#include "programa.h"
#include "GL/glew.h"
#include "GL/glut.h"
#include "GL/glext.h"
#include "camera.h"
#include "raio.h"
#include "ponto.h"
#include "esfera.h"
#include "material.h"
#include "luz.h"
#include "iluminacao.h"

static Esfera cenario[8];
static Camera camera(Ponto(1, 1, -1), Ponto(1, 1, 0));
static Luz luz(Vetor(1, 1, 1), Ponto(2, 2, 0.5));
static Vetor background(0.894f, 0.956f, 0.988f);
static Material neve(Vetor(0, 0, 0), Vetor(1, 1, 1), Vetor(0.3f, 0.3f, 0.3f), 2);
static Material pedra(Vetor(0, 0, 0), Vetor(0, 0, 0), Vetor(0.3f, 0.3f, 0.3f), 2);
static Material cenoura(Vetor(1, 0.498f, 0.313f), Vetor(0, 0, 0), Vetor(0.1f, 0.1f, 0.1f), 2);

Programa::Programa()
{

}

void Programa::setup(void)
{
    glClearColor(0, 0, 0, 0);
}

void Programa::desenharCenario(void)
{
    /*Camera camera(Ponto(1, 1, -1), Ponto(1, 1, 0));
    Luz luz(Vetor(1, 1, 1), Ponto(2, 2, 0.5));
    Vetor background(0.894f, 0.956f, 0.988f);
    Material neve(Vetor(0, 0, 0), Vetor(1, 1, 1), Vetor(0.3f, 0.3f, 0.3f), 2);
    Material pedra(Vetor(0, 0, 0), Vetor(0, 0, 0), Vetor(0.3f, 0.3f, 0.3f), 2);
    Material cenoura(Vetor(1, 0.498f, 0.313f), Vetor(0, 0, 0), Vetor(0.1f, 0.1f, 0.1f), 2);
    Esfera corpo(Ponto(1, 1, 0.5), 0.5f, neve);
    Esfera cabeca(Ponto(1, 1.5, 0.5), 0.3f, neve);
    Esfera olho1(Ponto(0.9, 1.55, 0.22), 0.03f, pedra);
    Esfera olho2(Ponto(1.1, 1.55, 0.22), 0.03f, pedra);
    Esfera nariz(Ponto(1, 1.5, 0.2), 0.03f, cenoura);
    Esfera botao1(Ponto(1, 1.21, 0.047f), 0.03f, pedra);
    Esfera botao2(Ponto(1, 1, 0), 0.03f, pedra);
    Esfera botao3(Ponto(1, 0.79, 0.047f), 0.03f, pedra);
    Esfera snowman[] = { corpo, cabeca, olho1, olho2, nariz, botao1, botao2, botao3 };*/
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_PROGRAM_POINT_SIZE_EXT);
    glPointSize(1);
    glBegin(GL_POINTS);
    for(int i = 0; i < Programa::largura; i++)
    {
        for(int j = 0; j < Programa::altura; j++)
        {
            Raio direcao = camera.lancarRaio(Ponto(i, j, 0), 500, 500);
            float t;
            float t_min = FLT_MAX;
            int pos = 0;
            for(int k = 0; k < 8; k++)
            {
                if(cenario[k].intercepta(direcao, &t))
                {
                    if(t < t_min)
                    {
                        pos = k;
                        t_min = t;
                    }
                }
            }
            if(t_min != FLT_MAX)
            {
                Esfera objeto = cenario[pos];
                Ponto ponto = camera.getOrigem().somar(direcao.getDirecao().multiplicar(t_min));
                Vetor normal = objeto.normal(ponto);
                Vetor cor = Iluminacao::calcularIluminacao(ponto, camera.getOrigem(), normal, luz, objeto.getMaterial());
                glColor3f(cor.getX(), cor.getY(), cor.getZ());
                glVertex3f(i, j, 0);
            }
            else
            {
                glColor3f(background.getX(), background.getY(), background.getZ());
                glVertex3f(i, j, 0);
            }
        }
    }
    glEnd();
    glFlush();
}

void Programa::redimensionar(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Programa::largura, 0, Programa::altura, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Programa::entradaTeclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

void Programa::show()
{
    cenario[0] = Esfera(Ponto(1.0f, 1.0f, 0.5f), 0.5f, neve); //corpo
    cenario[1] = Esfera(Ponto(1.0f, 1.5f, 0.5f), 0.3f, neve); //cabeca
    cenario[2] = Esfera(Ponto(0.9f, 1.55f, 0.22f), 0.03f, pedra); //olho1
    cenario[3] = Esfera(Ponto(1.1f, 1.55f, 0.22f), 0.03f, pedra); //olho2
    cenario[4] = Esfera(Ponto(1.0f, 1.5f, 0.2f), 0.03f, cenoura); //nariz
    cenario[5] = Esfera(Ponto(1.0f, 1.21f, 0.047f), 0.03f, pedra); //botao1
    cenario[6] = Esfera(Ponto(1.0f, 1.0f, 0.0f), 0.03f, pedra); //botao2
    cenario[7] = Esfera(Ponto(1.0f, 0.79f, 0.047f), 0.03f, pedra); //botao3
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Programa::largura, Programa::altura);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("snowman");
    glutDisplayFunc(desenharCenario);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(entradaTeclado);
    setup();
    glutMainLoop();
}
