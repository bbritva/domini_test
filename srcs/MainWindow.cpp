#include "MainWindow.h"

MainWindow::MainWindow() {
}

MainWindow::~MainWindow() {
	glutDestroyWindow(_windowDescriptor);
}

void MainWindow::drawStrokeText(GLfloat y, const char *text)
{
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	float scaleX = 1.5 * width / WINDOW_WIDTH;
	float scaleY = 1.5 * height / WINDOW_HEIGHT;
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,GLU_ORTO_WIDTH,0,GLU_ORTO_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef( width - 35 * strlen(text) * scaleX, y, 0);
	glScalef(scaleX, scaleY, 1);
	glLineWidth(2);
	for (int i = 0; text[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	glPopMatrix();
}

void MainWindow::drawButton(int y, std::string buttonName, t_eButton button)
{
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	gameCore->isButtonPressed(button) ? glColor3ub(BUTTON_PRESSED_COLOR) :
										glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2i(width / 2, y + height / 6);
	glVertex2i(width / 2, y - height / 6);
	glVertex2i(3 * width / 2, y - height / 6);
	glVertex2i(3 * width / 2, y + height / 6);
	glEnd();
	glColor3ub(TEXT_COLOR);
	drawStrokeText(y - height / 16, buttonName.c_str());
}

void MainWindow::refresh() {
	glutPostRedisplay();
}

void MainWindow::reshape(int width, int height) {
	gameCore->setHeight(height);
	gameCore->setWidth(width);
	glutPostRedisplay();
	std::cout << "w = " << width << ", h = " << height;
}

void MainWindow::clickOnMenu(int keyCode, int keyState, int x, int y)
{
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	if (keyCode != LEFT_MOUSE_BUTTON)
		return;
	if (x > width / 4 && x < 3 * width / 4)
	{
		int i = -1;
		while (++i < 3)
		{
			y = height - y;
			if (y > (1 + i) * height / 4 - height / 12 && y < (1 + i) * height / 4 + height / 12) {
				t_eButton button = static_cast<t_eButton>(2 - i);
				if (!keyState)
					gameCore->setButtonPressed(button);
				else {
					gameCore->resetButtons();
					gameCore->setButtonReleased(button);
				}
				return;
			}
		}
	}
}
void MainWindow::mouseClick(int keyCode, int keyState, int x, int y)
{
//	gameCore->setStateChanged(true);
	switch (gameCore->getState()) {
		case STATE_MENU:
			clickOnMenu(keyCode, keyState, x, y);
			break;
		case STATE_GAME:
			break;
		case STATE_GAME_MOVE_POSSIBILITIES:
			break;
		case STATE_END_GAME:
			break;
		default:
			break;

	}
}

void MainWindow::drawMenu()
{
	drawButton(gameCore->getHeight() / 2, "Exit", EXIT);
	drawButton(gameCore->getHeight(), "Credits", CREDITS);
	drawButton(1.5 * gameCore->getHeight(), "Start game", START);
}

void MainWindow::display()
{
	if (gameCore->isStateChanged()) {
		gameCore->setStateChanged(false);
		std::cout << "redraw\n";
		glClear(GL_COLOR_BUFFER_BIT);
		switch (gameCore->getState()) {
			case STATE_MENU:
				drawMenu();
				break;
			case STATE_GAME:
				break;
			case STATE_GAME_MOVE_POSSIBILITIES:
				break;
			case STATE_END_GAME:
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
