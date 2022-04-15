#include "MainWindow.h"

MainWindow::MainWindow() {
}

MainWindow::~MainWindow() {
	glutDestroyWindow(_windowDescriptor);
}

void MainWindow::drawStrokeText(GLfloat y, const char *text)
{
	glPushMatrix();
	glTranslatef(gameCore->getWidth()/ 2, y, 0);
	glScalef(1.5, 1.5, 1);
	glLineWidth(2);
	for (int i = 0; text[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	glPopMatrix();
}

void MainWindow::drawButton(int y, std::string buttonName)
{
	t_eButton button = static_cast<t_eButton>((y - GLU_ORTO_HEIGHT / 6) * 3);
	gameCore->isButtonPressed(button) ? glColor3ub(BUTTON_PRESSED_COLOR) :
										glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2i(GLU_ORTO_WIDTH / 4, y + GLU_ORTO_HEIGHT / 12);
	glVertex2i(GLU_ORTO_WIDTH / 4, y - GLU_ORTO_HEIGHT / 12);
	glVertex2i(3 * GLU_ORTO_WIDTH / 4, y - GLU_ORTO_HEIGHT / 12);
	glVertex2i(3 * GLU_ORTO_WIDTH / 4, y + GLU_ORTO_HEIGHT / 12);
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
	x *= 2;
	y *= 2;
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
	else
		gameCore->resetButtons();
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
	drawButton(GLU_ORTO_HEIGHT / 6, "Start game");
	drawButton(GLU_ORTO_HEIGHT / 2, "Credits");
	drawButton(5 * GLU_ORTO_HEIGHT / 6, "Exit");
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
