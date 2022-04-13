//
// Created by bbritva on 11.04.2022.
//

#include "MainWindow.h"


MainWindow::MainWindow(int *argc, char **argv) {
	_argc = argc;
	_argv = argv;
    _state = MENU;
}

MainWindow::~MainWindow() {

}

void MainWindow::drawButton(int y, std::string buttonName)
{
	glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2f(-600 ,y + 150);
	glVertex2f(-600 ,y - 150);
	glVertex2f(600 ,y - 150);
	glVertex2f(600 ,y + 150);
	glEnd();
	glColor3ub(TEXT_COLOR);
	drawStrokeText(y, buttonName.c_str());
//	drawBitmapText(y, buttonName.c_str());
}

void refresh() {
	glutPostRedisplay();
}

void mouseClick(int a, int b, int x, int y)
{
	printf("a = %d, b = %d, x = %d, y = %d\n", a, b, x, y);
}

void display()
{
	static bool firstTime = true;
	if (firstTime)
	{
		firstTime = false;
		glClear(GL_COLOR_BUFFER_BIT);
		this.drawButton(500, "Start game");
		drawButton(0, "Credits");
		drawButton(-500, "Exit");
		glutPostRedisplay();
		glFlush();
		glLoadIdentity();
		glutSwapBuffers();
	}
}

int MainWindow::start()
{
	glutInit(_argc, _argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	_windowDescriptor = glutCreateWindow(GAME_NAME);
	glClearColor(0.0,0.0,0.0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1200,1200,-1200,1200);
	glMatrixMode(GL_MODELVIEW);
	glutIdleFunc(refresh);
	glutMouseFunc(mouseClick);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
