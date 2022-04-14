#include "main.h"

GameCore *gameCore;

int main(int argc, char **argv)
{
	int windowDescriptor;

	windowDescriptor = init(&argc, argv);
	addEventHandlers();
	glutMainLoop();
	glutDestroyWindow(windowDescriptor);
	return 0;
}

void addEventHandlers() {
	glutIdleFunc(MainWindow::refresh);
	glutMouseFunc(MainWindow::mouseClick);
	glutDisplayFunc(MainWindow::display);
}

int init(int *argc, char **argv)
{
	gameCore = new GameCore();
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	int windowDescriptor = glutCreateWindow(GAME_NAME);
	glClearColor(0.0,0.0,0.0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1200,1200,-1200,1200);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	return windowDescriptor;
}