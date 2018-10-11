#include "programa.h"
#include "GL/glut.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    Programa w;
    w.show();

    return a.exec();
}
