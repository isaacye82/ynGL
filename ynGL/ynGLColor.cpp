#include "glut.h"
#include <math.h>

//作个测试，在云端修改，看本地是否能用git单独文件更新
void SetupRC()
{
	glClearColor(0., 0., 0., 1.0);
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);
//	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLES);
		glColor3ub(255, 0, 0);
		glVertex2f(-0.5, -0.5);
		glColor3ub(0, 255, 0);
		glVertex2f(0.5, -0.5);
		glColor3ub(0, 0, 255);
		glVertex2f(0., 0.5);
	glEnd();

	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("color");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

	return 0;
}
