#include "MainWindow.h"

MainWindow::MainWindow() {
}

MainWindow::~MainWindow() {
	glutDestroyWindow(_windowDescriptor);
}

void MainWindow::drawStrokeText(GLfloat y, const char *text)
{
	glPushMatrix();
	glTranslatef(-50 * (float)strlen(text), y - 50, 0);
	glScalef(1.5, 1.5, 1.5);
	glLineWidth(2);
	for (int i = 0; text[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	glPopMatrix();
}

void MainWindow::drawButton(int y, std::string buttonName)
{
	glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2f(-600, y + 150);
	glVertex2f(-600, y - 150);
	glVertex2f(600, y - 150);
	glVertex2f(600, y + 150);
	glEnd();
	glColor3ub(TEXT_COLOR);
	drawStrokeText(y, buttonName.c_str());
}

void MainWindow::refresh() {
	glutPostRedisplay();
}

void MainWindow::mouseClick(int a, int b, int x, int y)
{
	printf("a = %d, b = %d, x = %d, y = %d\n", a, b, x, y);
}

void MainWindow::drawMenu()
{
	drawButton(500, "Start game");
	drawButton(0, "Credits");
	drawButton(-500, "Exit");
}

void MainWindow::display()
{
	if (gameCore->isStateChanged()) {
		glClear(GL_COLOR_BUFFER_BIT);
		switch (gameCore->getState()) {
			case MENU:
				drawMenu();
				break;
			case GAME:
				break;
			case GAME_MOVE_POSSIBILITIES:
				break;
			case GAME_MOVING:
				break;
			case END_GAME:
				break;
			default:
				break;

		}
		glutPostRedisplay();
		glFlush();
		glLoadIdentity();
		glutSwapBuffers();
	}
}
