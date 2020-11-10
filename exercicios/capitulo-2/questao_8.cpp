#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

#pragma comment(lib, "glew32.lib")

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    
    glBegin(GL_POLYGON);
    glVertex3f(-20, -20, 0);
    glVertex3f(80, 20, 0);
    glVertex3f(120, 120, 0);
    glVertex3f(20, 80, 0);
    glEnd();

    glFlush();
}

void setup()
{
    glClearColor(1, 1, 1, 0);
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27: exit(0);
            break;
        default: break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitContextVersion(3, 0);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("questao_8");
    
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}