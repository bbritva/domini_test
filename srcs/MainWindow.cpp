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
	t_eButton button = static_cast<t_eButton>((y + 500) / 3);
	gameCore->isButtonPressed(button) ? glColor3ub(BUTTON_PRESSED_COLOR) :
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

void MainWindow::clickOnMenu(int keyCode, int keyState, int x, int y)
{
	std::cout << "mouse 0\n";

	if (keyCode != LEFT_MOUSE_BUTTON)
		return;
	if (!keyState && x > -600 && x < 600)
	{
		std::cout << "mouse 1\n";
		int i = -1;
		while (++i < 3)
		{
			y -= 500;
			if (y > -150 + i * 500 && y < 150 + i * 500) {
				gameCore->setButtonPressed(static_cast<t_eButton>(i));
				return;
			}
		}
	}
//	else
//		gameCore->resetButtons();
}
void MainWindow::mouseClick(int keyCode, int keyState, int x, int y)
{
//	gameCore->setStateChanged(true);
	switch (gameCore->getState()) {
		case MENU:
			clickOnMenu(keyCode, keyState, x, y);
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
	printf("keyCode = %d, keyState = %d, x = %d, y = %d\n", keyCode, keyState, x, y);
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
		gameCore->setStateChanged(false);
		std::cout << "redraw\n";
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
