

// Points.c
// OpenGL SuperBible, Chapter 3
// Demonstrates OpenGL Primative GL_POINTS
// Program by Richard S. Wright Jr.

#include "glut.h"
#include <math.h>


// Define a constant for the value of PI
#define GL_PI 3.1415f

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;

// Called to draw scene
void RenderScene(void)
{
	GLfloat x, y, z, angle; // Storeage for coordinates and angles

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Save matrix state and do the rotation
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f); // 注意模型变换的顺序
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);

	glColor3f(1., 1., 0); //设置当前颜色
	glRectf(-25.0, 25.0, 25.0, -25.0);

	//画坐标轴
	glBegin(GL_LINES);
		glColor3f(1., 0., 0.);
		glVertex3f(0., 0., 0.);
		glVertex3f(50., 0., 0.);
		glColor3f(0., 1., 0.);
		glVertex3f(0., 0., 0.);
		glVertex3f(0., 50., 0.);
		glColor3f(0., 0., 1.);
		glVertex3f(0., 0., 0.);
		glVertex3f(0., 0., 50.);
	glEnd();
	   

	// Call only once for all remaining points
	glBegin(GL_POINTS);
//	glBegin(GL_LINE_STRIP);
	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	z = -50.0f;
	for (angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
	{
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);

		// Specify the point and move the Z value up a little	
		glVertex3f(x, y, z);
		z += 0.5f;
	}

	// Done drawing points
	glEnd();

	// Restore transformations
	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_HOME)
		xRot -= 5.0f;

	if (key == GLUT_KEY_END)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key == GLUT_KEY_UP)
		zRot += 5.0f;

	if (key == GLUT_KEY_DOWN)
		zRot -= 5.0f;

	if (xRot > 356.0f)
		xRot = 0.0f;

	if (xRot < -1.0f)
		xRot = 355.0f;

	if (yRot > 356.0f)
		yRot = 0.0f;

	if (yRot < -1.0f)
		yRot = 355.0f;

	if (zRot > 356.0f)
		zRot = 355.0f;

	if (zRot < -1.0f)
		zRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
}


void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Points Example");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

	return 0;
}
