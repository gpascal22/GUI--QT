/*

 Author: Daniel Palmer

*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{
}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
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
    glOrtho(3, -3, -3, 3, -2, 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    float radius = 0.4;
    
    
    //Draw a point
    glLoadIdentity();
    glTranslatef(-1,1,0);
    glPointSize(8);
    glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
        glVertex2i(-0.75,0.5);
    glEnd();
	
	
    //Draw a line
    glLoadIdentity();
    glTranslatef(1.25,-1,0);
    glRotatef(45.0, 0.0, 1.0, 1.0);
    glLineWidth(5);
    glBegin(GL_LINES);
	glColor3f(0.0, 3, 0.0);
	glVertex2f(0.75,0.75);
        glVertex2f(0.25,0.25);
     glEnd();

    //Draw a quad
    glLoadIdentity();
    glTranslatef(-1.0,-1.0,1);
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glColor3f (0.0, 0.0, 1.0);
        glVertex3f(-radius, -radius,  radius);
        glVertex3f( radius, -radius,  radius);
        glVertex3f( radius,  radius,  radius);
        glVertex3f(-radius,  radius,  radius);
    glEnd();
    
    //Draw a triangle
    glLoadIdentity();
    glTranslatef(-1, 2,1);
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-1,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,1,0);
        glColor3f(0,0,1);
        glVertex3f(1,0,0);
    glEnd();
    
    //Draw a yellow circle
    glLoadIdentity();
    glTranslatef(1.0,2.0,0);
    glRotatef(90.0, 1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,0.0);
    for (int i = 0; i < 100; i++)   {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float x = 0.7 * cosf(theta);
        float y = 0.7 * sinf(theta);
        glVertex2f(x + 0, y + 0);
    }
    glEnd();

    //Draw a circle
    glLoadIdentity();
    glTranslatef(0.0,-2,0.0);
    glRotatef(45.0, -1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    for (int i = 0; i < 100; i++)   {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float x = 0.4 * cosf(theta);
        float y = 0.4 * sinf(theta);
        glVertex2f(x + 0, y + 0);
    }
    glEnd();
    
    //Draw a hexagon
    glLoadIdentity();
    glTranslatef(2, -2,1);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 1.0); 
		glVertex2f(-0.13, -0.2);
		glVertex2f(0.13, -0.2);
		glVertex2f(0.2, 0.0);
		glVertex2f(0.13, 0.2);
		glVertex2f(-0.13, 0.2);
		glVertex2f(-0.2, 0.0);
	glEnd();

    glFlush ();
}










