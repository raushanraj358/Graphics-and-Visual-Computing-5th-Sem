/*
For compiling this code on linux/ ubuntu , use the command written below :
g++ IIT2018031_Assignment6.cpp -o extrude -lglut -lGLU -lGL
./extrude
*/

#include<bits/stdc++.h>
using namespace std;
#include <GL/glut.h>


#define PI 3.1415927

void drawCurve(float x0,float y0,float x1,float y1,float h0,float angle)
{
    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);

    double x[]={x0,(x0+x1+0.05*(x0+x1>0?1:-1))/2,(x0+x1+0.05*(x0+x1>0?1:-1))/2,x1};
    double y[]={y0,(y0+y1+0.05*(y0+y1>0?1:-1))/2,(y0+y1+0.05*(y0+y1>0?1:-1))/2,y1};

	double xu = 0.0 , yu = 0.0, u = 0.0 ; 
	int i = 0 ; 
	for(u = 0.0 ; u <= 1.0 ; u += 0.0001) 
	{ 
		xu = pow(1-u,3)*x[0]+3*u*pow(1-u,2)*x[1]+3*pow(u,2)*(1-u)*x[2] 
			+pow(u,3)*x[3]; 
		yu = pow(1-u,3)*y[0]+3*u*pow(1-u,2)*y[1]+3*pow(u,2)*(1-u)*y[2] 
			+pow(u,3)*y[3]; 
        glVertex3f(xu,yu,h0);
	} 

    glEnd();
    glPopMatrix();
    glLineWidth(1.0);
}

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = M_PI/4;

    glColor3f(0.0,0.0,1.0);
    
    for (float h=0;h<height;h+=height/5){
        
        angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);

            glBegin(GL_LINES);
            glVertex3f(x, y , h);
            glVertex3f(x, y , h+height/5);
            glEnd();

            angle = angle + angle_stepsize;
            drawCurve(x,y,radius * cos(angle),radius * sin(angle),h,PI/4);
        }
    }

    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);

        angle = angle + angle_stepsize;
        drawCurve(x,y,radius * cos(angle),radius * sin(angle),height,PI/4);

    }

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,-0.4,-3.0);
    glRotatef(-40, 1.0, 0.0, 0.0);

    draw_cylinder(0.3, 1.0, 255, 160, 100);

    glFlush();
}

void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height,
                   0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("CYLINDER USING BEIZER AND EXTRUSION");
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}