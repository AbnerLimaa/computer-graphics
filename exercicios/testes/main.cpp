//
//  main.cpp
//  RayCastPsyco
//
//  Created by Creto Vidal on 06/09/18.
//  Copyright © 2018 Creto Vidal. All rights reserved.
//

#include <cmath>
#include <iostream>
//#include <>


#ifdef __APPLE__
//#  include <GL/glew.h>
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#else
//#  include <GL/glew.h>
#  include <GLUT/glut.h>
#  include <OpenGL/glext.h>
#pragma comment(lib, "glew64.lib")
#endif

#define PI 3.14159265

using namespace std;

// Globals.
static unsigned int   W_Npixels = 1000, H_Npixels = 1000;
static float          W = 50., H = 50.;


// Drawing routine.
void drawScene(void)
{
    float x, y, Dx, Dy;
    float r, g, b;
    
    //int   IL = H_Npixels/8, IC = W_Npixels/8;
    
    Dx = W/W_Npixels;
    Dy = H/H_Npixels;
    
    glClear (GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    
    glTranslated(0, 0, -2.5);
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    
    
    glBegin(GL_POINTS);
    
        for (int l = 0; l < H_Npixels; l++)
        {
            y = H/2 - Dy/2 - l*Dy;
            
            
            
            /*
            r = (l/100)*0.1;
            g = 0.0;
            b = 0.5;
            */
            
            //glColor3f(r, g, b);
            
            for (int c = 0; c < W_Npixels; c++)
            {
                x = -W/2 + Dx/2 + c*Dx;
                
                
                //r = g = b = 1.0;
                /*
                if ((((l/IL)%2 == 0) && ((c/IC)%2 == 0)) || (((l/IL)%2 == 1) && ((c/IC)%2 == 1)) )
                {
                    r = g = b = 0.0;
                }
                else
                {
                    r = g = b = 1.0;
                }
                
                //g =  (c/100)*0.1;
                glColor3f(r, g, b);
                 */
                glColor3f((rand()%255)/255., (rand()%255)/255., (rand()%255)/255.);
                glVertex3f(x, y, -1.);
            }
        }
    glEnd();
    
    glFlush();
}

// Initialization routine.
void setup(void)
{
    
    glClearColor(0.53, 0.81, 0.98, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    int wsize = w, hsize = h;
    if (h >= w)
    {
        hsize = w*H/W;
        glViewport(0, (h-hsize)/2, wsize, hsize);
    }
    else if (h < w)
    {
        wsize = h*W/H;
        glViewport((w-wsize)/2, 0,  wsize, hsize);
    }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-W/2, W/2, -H/2, H/2, 1.0, 10.0);
    // glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    // gluPerspective(90.0, 1.0, 5.0, 100.0);
    // gluPerspective(90.0, (float)w/(float)h, 5.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
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
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(W_Npixels, H_Npixels);
    glutInitWindowPosition(000, 000);
    glutCreateWindow("Psycodelic Canvas");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    
    setup();
    
    glutMainLoop();
}

