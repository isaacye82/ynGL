// LookAt.cpp : Defines the entry point for the console application.
//
// Choose.cpp : Defines the entry point for the console application.
//

#include "glut.h"
#include <windows.h>
#include <stdio.h>

void drawTriangle(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3,GLfloat z)
{
	glBegin(GL_TRIANGLES);
	    glVertex3f(x1,y1,z);
		glVertex3f(x2,y2,z);
		glVertex3f(x3,y3,z);
	glEnd();
}

void drawViewVolume(GLfloat x1,GLfloat x2,GLfloat y1,GLfloat y2,GLfloat z1,GLfloat z2)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	    glVertex3f(x1,y1,-z1);
		glVertex3f(x2,y1,-z1);
		glVertex3f(x2,y2,-z1);
		glVertex3f(x1,y2,-z1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	    glVertex3f(x1,y1,-z2);
		glVertex3f(x2,y1,-z2);
		glVertex3f(x2,y2,-z2);
		glVertex3f(x1,y2,-z2);
	glEnd();
	glBegin(GL_LINES);
	    glVertex3f(x1,y1,-z1);
		glVertex3f(x1,y1,-z2);
		glVertex3f(x1,y2,-z1);
		glVertex3f(x1,y2,-z2);
	    glVertex3f(x2,y1,-z1);
		glVertex3f(x2,y1,-z2);
		glVertex3f(x2,y2,-z1);
		glVertex3f(x2,y2,-z2);
	glEnd();
}

void drawScene()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,4.0/3.0,0.01,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(7.5,7.5,12.5,2.5,2.5,-5.0,0.0,1.0,0.0);
//	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glColor3f(0.0,1.0,0.0);
	glColor3f(1.0,1.0,0.0);
	drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,-5.0);
	glColor3f(1.0,0.0,0.0);
	drawTriangle(2.0,7.0,3.0,7.0,2.5,8.0,-5.0);
	glColor3f(1.0,1.0,0.0);
	drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,0.0);
	//drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,-10.0);
	//drawViewVolume(0.0,5.0,0.0,5.0,0.0,10.0);
}

void processHits(GLint hits,GLuint buffer[])
{
	unsigned int i,j;
	GLuint names,*ptr;

	printf("hits=%d\n",hits);
	ptr=(GLuint *)buffer;
	for(i=0;i<hits;i++){
		names=*ptr;
		printf("number of name for hit=%d",names);
		ptr++;
		printf("z1 is %u;",*ptr);
		ptr++;
		printf("z2 is %u\n",*ptr);
		ptr++;
		printf(" the name is ");
		for(j=0;j<names;j++){
			printf("%d",*ptr);
			ptr++;
		}
		printf("\n");
	}
}

#define BUFSIZE 512

void selectObjects()
{
	GLuint selectBuf[BUFSIZE];
	GLint hits,viewport[4];

	glSelectBuffer(BUFSIZE,selectBuf);
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(-1);

	glPushMatrix();
	    glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0,5.0,0.0,5.0,0.0,10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glLoadName(1);
        drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,-5.0);
	    glLoadName(2);
	    drawTriangle(2.0,7.0,3.0,7.0,2.5,8.0,-5.0);
		glLoadName(3);
	    drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,0.0);
     	drawTriangle(2.0,2.0,3.0,2.0,2.5,3.0,-10.0);
	glPopMatrix();
	glFlush();
	hits=glRenderMode(GL_RENDER);
	processHits(hits,selectBuf);
}

void myInit()
{
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawScene();
	selectObjects();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Ñ¡ÔñÄ£Ê½");
	
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}