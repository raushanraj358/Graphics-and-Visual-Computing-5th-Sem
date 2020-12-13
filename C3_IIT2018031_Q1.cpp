#include <stdio.h>
#include<windows.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;


void myInit()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    // this code (mostly) copied from question:
    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}

void drawRectangle()
{
    int w = 150;

    for(int i=200;i<800;i+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(68,114,196);
        glVertex2f(i,i);
        glVertex2f(i,i+w);
        glVertex2f(i+w,i+w);
        glVertex2f(i+w,i);
        glEnd();
    }

    for(int i=350,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(237,125,49);
        glVertex2f(i,j);
        glVertex2f(i,j+w);
        glVertex2f(i+w,j+w);
        glVertex2f(i+w,j);
        glEnd();
    }

    for(int i=500,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(68,114,196);
        glVertex2f(i,j);
        glVertex2f(i,j+w);
        glVertex2f(i+w,j+w);
        glVertex2f(i+w,j);
        glEnd();
    }

    for(int i=650,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(112,173,71);
        glVertex2f(i,j);
        glVertex2f(i,j+w);
        glVertex2f(i+w,j+w);
        glVertex2f(i+w,j);
        glEnd();
    }

    glColor3ub(171,171,171);
    draw_circle(725,850,50);


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1.0, 0.0, 0.0);
    drawRectangle();
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("IIT2018031_Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
