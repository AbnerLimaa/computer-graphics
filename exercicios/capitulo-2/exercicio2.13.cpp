////////////////////////////////////////////////////          
// experimentTwoSquares.cpp
// (modifying square.cpp)
// 
// Sumanta Guha.
////////////////////////////////////////////////////

#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif

// Drawing routine.
void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(20.0, 20.0, 0.0);
      glVertex3f(10.0, 10.0, 0.0);
      glVertex3f(20.0, 60.0, 0.0);
      glVertex3f(10.0, 70.0, 0.0);
      glVertex3f(60.0, 60.0, 0.0);
      glVertex3f(70.0, 70.0, 0.0);
      glVertex3f(60.0, 20.0, 0.0);
      glVertex3f(70.0, 10.0, 0.0);
      glVertex3f(20.0, 20.0, 0.0);
      glVertex3f(10.0, 10.0, 0.0);
   glEnd();

   glFlush(); 
}

// Initialization routine.
void setup(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0); 
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
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

// Main routine.
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);

   glutInitContextVersion(3, 0);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("exercicio2.13.cpp");
   glutDisplayFunc(drawScene); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);

   glewExperimental = GL_TRUE;
   glewInit();

   setup(); 
   
   glutMainLoop(); 
}