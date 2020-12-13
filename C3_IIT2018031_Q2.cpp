#include <stdio.h>
#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
using namespace std;

int x = 725,y = 850;
void myInit()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void Timer(int value) {
    glutTimerFunc(1000, Timer, value);
    glutPostRedisplay();
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


void delay(float secs)
{
  float end = clock() / CLOCKS_PER_SEC + secs;
  while ((clock() / CLOCKS_PER_SEC) < end);
}
int count = 0;

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
    draw_circle(x,y,50);


    // if(x == 150 && y == 250)
    // {
    //     return;
    // }
    if(count == 0)
    {
        x-= 35;
        y += 50;

    }
    if(count == 1)
    {
        x-= 35;
        y+= 50;

    }
    if(count == 2)
    {
        x-= 20;
        y-= 50;
    }
    if(count == 3)
    {
        x-= 20;
        y-= 50;
    }
    if(count == 4)
    {
        x-= 20;
        y-= 75;
    }
    if(count == 5)
    {
        x-= 20;
        y-= 75;
    }
    count = (count+1)%6;

}

void myDisplay()
{
    int n = 25;
    while(n--)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        drawRectangle();
        glEnd();
        glFlush();
        delay(0.01);
    }

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("LAB TEST_IIT2018031");
    myInit();
    glutDisplayFunc(myDisplay);
    // glutIdleFunc(myDisplay);
    glutMainLoop();
}
