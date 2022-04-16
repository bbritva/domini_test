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

void MainWindow::drawButton(int y, std::string buttonName)
{
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	t_eButton button = static_cast<t_eButton>((y - height / 3) * 3);
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
	std::cout << "mouse 0\n";
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	if (keyCode != LEFT_MOUSE_BUTTON)
		return;
	if (!keyState && x > width / 4 && x < 3 * width / 4)
	{
		std::cout << "mouse 1\n";
		int i = -1;
		while (++i < 3)
		{
			y = height - y;
			if (y > - height / 6 + i * 2 * height / 3 && y < height / 6 + i * 2 * height / 3) {
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
	drawButton(gameCore->getHeight() / 3, "Exit");
	drawButton(gameCore->getHeight(), "Credits");
	drawButton(5 * gameCore->getHeight() / 3, "Start game");
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
