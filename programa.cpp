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

Programa::Programa()
{

}

void Programa::setup(void)
{
    glClearColor(0, 0, 0, 0);
}

void Programa::desenharCenario(void)
{
    Camera camera(Ponto(250, 250, -500), Ponto(250, 250, -400));
    Luz luz(Vetor(1, 1, 1), Ponto(500, 500, -300));
    Vetor background(0.894f, 0.956f, 0.988f);
    Material neve(Vetor(0, 0, 0), Vetor(1, 1, 1), Vetor(0.3f, 0.3f, 0.3f), 2);
    Esfera esfera1(Ponto(250, 250, -300), 100, neve);
    Esfera esfera2(Ponto(250, 380, -300), 50, neve);
    Esfera snowman[] = { esfera1, esfera2 };
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
            for(int k = 0; k < 2; k++)
            {
                if(snowman[k].intercepta(direcao, &t))
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
                Esfera objeto = snowman[pos];
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
