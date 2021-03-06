#include "main.h"

GameCore *gameCore;

int main(int argc, char **argv)
{
	int windowDescriptor;

	windowDescriptor = init(&argc, argv);
	if (!windowDescriptor)
		return 0;
	addEventHandlers();
	glutMainLoop();
	glutDestroyWindow(windowDescriptor);
	delete gameCore;
	return 0;
}

void addEventHandlers() {
	glutIdleFunc(MainWindow::refresh);
	glutMouseFunc(MainWindow::mouseClick);
	glutDisplayFunc(MainWindow::display);
	glutReshapeFunc(MainWindow::reshape);

}

int init(int *argc, char **argv)
{
	gameCore = new GameCore();
	if (!gameCore)
		return 0;
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(gameCore->getWidth(), gameCore->getHeight());
	int windowDescriptor = glutCreateWindow(GAME_NAME);
	gameCore->setWindowDescriptor(windowDescriptor);
	glClearColor(0.0,0.0,0.0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,GLU_ORTO_WIDTH,0,GLU_ORTO_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	return windowDescriptor;
}