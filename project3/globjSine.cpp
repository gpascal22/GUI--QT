#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globjSine.h"

GLobjS::GLobjS(QWidget *parent)
    : QGLWidget(parent)
{
}

GLobjS::~GLobjS()
{

}

//Initialize the GL settings
void GLobjS::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobjS::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene
void GLobjS::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);


	float x1, x2, y1, y2;
	glLoadIdentity();
	glTranslatef(-1,0,0);
	for (int i=0;i<2000;i++)
	{
		x1=(float)i/2000;
		x2=((float)i+1)/2000;
		y1=sin(x1*15*3.14575);
		y2=sin(x2*15*3.14575);
	glBegin(GL_LINE_STRIP); 
		glColor3f(1.0,0,0);
		glVertex2f(2*x1,y1);
		glVertex2f(2*x2,y2);
	glEnd();
	}
    glFlush ();
}



