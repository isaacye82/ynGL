// ynGL.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "glut.h"

void SetupRC()
{
	glClearColor(0.2, 0.2, 0.2, 1); //����ˢ�±���ɫ 
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); //ˢ�±��� 

	glColor3f(1, 0, 0); //���õ�ǰ��ɫ
	glRectf(-25.0, 25.0, 25.0, -25.0);
	//	glRectf(-0.5, 0.5, 0.5, -0.5);

	glFlush();	//���´��� 
}

void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
	if (h == 0) {
		h = 1;
	}

	//	glViewport(0, 0, w/2, h/2);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w < h) {
		// ����100�ǿ��Ըı�ģ���Ӧ��ʵ���������б������ķ�Χ��
		// ���磺һ�������������ķ�Χ������200m x 200m �������α�ʾ����λΪm
		glOrtho(-100., 100., -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	}
	else {
		glOrtho(-100.*aspectRatio, 100.*aspectRatio, -100, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	//������ʾģʽ������������ RGBA��ɫģʽ 
	glutInitWindowSize(200, 200); 	                //���ô��ڿ�ȡ��߶� 
	glutCreateWindow(argv[0]);	                    //�������� 

	SetupRC();

	glutDisplayFunc(RenderScene);	//���ô���ˢ�µĻص����� 
	glutReshapeFunc(ChangeSize);

	glutMainLoop();               	//��ʼ��ѭ�� 
	return 0;
}

