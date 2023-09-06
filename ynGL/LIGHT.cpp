// LIGHT.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "glut.h"
#define TORUS 0
#define TEAPOT 1
#define CONE 2
#define ICO 3
#define QUIT 4

static int spin;
static int obj=TORUS;
static int begin;

void menu_select(int item)
{
	if (item == QUIT)
		//	exit(0);
		return;
	else{
		obj=item;
		spin=0;
	}
	glutPostRedisplay();
}

void moveLight(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
		begin=x;
	}
}

void motion(int x,int y)
{
	spin=(spin+x-begin)%360;
	begin=x;
	glutPostRedisplay();
}

void init()
{   
	GLfloat ambient[]={0.0,0.0,0.0,1.0};
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	GLfloat diffuse[]={1.0,1.0,1.0,1.0}; 
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
	GLfloat specular[]={1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
}

void display()
{
	GLfloat position[]={0.0,0.0,1.5,1.0};

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
        glTranslatef(0.0,0.0,-5.0);
		glPushMatrix();
		    glRotated((GLdouble)spin,0.0,1.0,0.0);
			glLightfv(GL_LIGHT0,GL_POSITION,position);
			glTranslatef(0.0,0.0,1.5);
			glDisable(GL_LIGHTING);
			glColor3f(1.0,1.0,0.0);
			glutWireSphere(0.05,8.0,8.0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		switch(obj){
		case TORUS:
			glutSolidTorus(0.27,0.8,20,20);
			break;
		case TEAPOT:
			glutSolidTeapot(1.0);
			break;
		case CONE:
			glPushMatrix();
			    glTranslatef(0.0,-0.8,0.0);
				glRotatef(-90.0,1.0,0.0,0.0);
				glutSolidCone(1.0,2.0,20.0,20.0);
			glPopMatrix();
			break;
		case ICO:
			glutSolidIcosahedron();
			break;
		}
	glPopMatrix();
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLfloat)w/(GLfloat)h,1.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[])
{   
	glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("light");
	init();
	glutMouseFunc(moveLight);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutCreateMenu(menu_select);
	glutAddMenuEntry("Torus",TORUS);
    glutAddMenuEntry("Teapot",TEAPOT);
    glutAddMenuEntry("Cone",CONE);
    glutAddMenuEntry("Icosahedron",ICO);
    glutAddMenuEntry("Quit",QUIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
