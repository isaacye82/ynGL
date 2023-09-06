// ynGL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "glut.h"

void SetupRC()
{
	glClearColor(0.2, 0.2, 0.2, 1); //设置刷新背景色 
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT); //刷新背景 

	glColor3f(1, 0, 0); //设置当前颜色
	glRectf(-25.0, 25.0, 25.0, -25.0);
	//	glRectf(-0.5, 0.5, 0.5, -0.5);

	glFlush();	//更新窗口 
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
		// 数字100是可以改变的，对应真实物理世界中表达坐标的范围，
		// 比如：一个大型体育场的范围，可以200m x 200m 的正方形表示，单位为m
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	//设置显示模式：单缓冲区， RGBA颜色模式 
	glutInitWindowSize(200, 200); 	                //设置窗口宽度、高度 
	glutCreateWindow(argv[0]);	                    //弹出窗口 

	SetupRC();

	glutDisplayFunc(RenderScene);	//设置窗口刷新的回调函数 
	glutReshapeFunc(ChangeSize);

	glutMainLoop();               	//开始主循环 
	return 0;
}

