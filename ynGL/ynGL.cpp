// ynGL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "glut.h"

void SetupRC()
{
	glClearColor(1, 1, 1, 1); //设置刷新背景色 
}

void RenderScene()
{	
	glClear(GL_COLOR_BUFFER_BIT); //刷新背景 
	
	glColor3f(1, 0, 0); //设置当前颜色
	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.9, -0.9, 0);
		glVertex3f(0.9, -0.9, 0);
		glVertex3f(0.9, 0.9, 0);
		glVertex3f(-0.9, 0.9, 0);
	glEnd();

	glColor3f(0, 1, 0); //设置当前颜色
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1.0);
		glVertex3f(-0.5, -0.5, 0);
		glVertex3f(0.5, -0.5, 0);
		glVertex3f(0.5, 0.5, 0.);
		glVertex3f(-0.5, 0., 0.);
	glEnd();
	
	glFlush();	//更新窗口 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	//设置显示模式：单缓冲区， RGBA颜色模式 
	glutInitWindowSize(200, 200); 	                //设置窗口宽度、高度 
	glutCreateWindow(argv[0]);	                    //弹出窗口 
	
	SetupRC();
	
	glutDisplayFunc(RenderScene);	//设置窗口刷新的回调函数 
	glutMainLoop();               	//开始主循环 
	return 0;
}

