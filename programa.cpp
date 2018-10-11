#include "programa.h"
#include "GL/glew.h"
#include "GL/glut.h"
#include "GL/glext.h"
#include "camera.h"
#include "raio.h"
#include "ponto.h"
#include "esfera.h"

Programa::Programa()
{

}

void Programa::setup(void)
{
    glClearColor(0, 0, 0, 0);
}

void Programa::desenharCenario(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Camera camera(Ponto(0, 0, 1));
    Esfera esfera(Ponto(0, 0, 10), 4);
    glColor3f(1, 1, 1);
    float t;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            Raio direcao = camera.lancarRaio(Ponto(i, j, 0), 100, 100);
            if(esfera.intercepta(direcao, &t))
                glVertex3f(i, j, 0);
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
    glOrtho(0, 100, 0, 100, -1, 1);
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
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("snowman");
    glutDisplayFunc(desenharCenario);
    glutReshapeFunc(redimensionar);
    glutKeyboardFunc(entradaTeclado);
    setup();
    glutMainLoop();
}
