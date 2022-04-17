#include "main.h"

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

void MainWindow::drawChecker(int i, int j, t_eCell cell)
{
	float cx = (2.0f * gameCore->getWidth() / FIELD_SIZE) * (0.5f + i);
	float cy = (2.0f * gameCore->getHeight() / FIELD_SIZE) * (0.5f + j);
	float r = gameCore->getWidth() / FIELD_SIZE;
	cell == CELL_PLAYER_1 ? glColor3ub(COLOR_CHECKER_PLAYER_1) :
							glColor3ub(COLOR_CHECKER_PLAYER_2);
	glBegin(GL_POLYGON);
	for(int k = 0; k < 32; k++)
	{
		float theta = 2.0f * 3.1415926f * k / 32;//get the current angle
		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component
		glVertex2f(x + cx, y + cy);//output vertex
	}
	glEnd();
}
void MainWindow::drawButton(int y, std::string buttonName, t_eButton button)
{
	int height = gameCore->getHeight();
	int width = gameCore->getWidth();
	gameCore->isButtonPressed(button) ? glColor3ub(COLOR_BUTTON_PRESSED) :
										glColor3ub(COLOR_BUTTON);
	glBegin(GL_POLYGON);               //Border
	glVertex2i(width / 2, y + height / 6);
	glVertex2i(width / 2, y - height / 6);
	glVertex2i(3 * width / 2, y - height / 6);
	glVertex2i(3 * width / 2, y + height / 6);
	glEnd();
	glColor3ub(COLOR_TEXT);
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
					gameCore->setButtonReleased(button);
				}
				return;
			}
		}
	}
	gameCore->resetButtons();
}
void MainWindow::mouseClick(int keyCode, int keyState, int x, int y)
{
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
	drawButton(3 * gameCore->getHeight() / 2, "Start game", START);
}

void MainWindow::drawCheckers()
{
	t_eCell cell;
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			cell = gameCore->getCell(i,j);
			if (cell != CELL_EMPTY) {
				drawChecker(i, j, cell);
			}
		}
	}
}

void MainWindow::drawGameField()
{
	drawCells();
	drawCheckers();
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
				drawGameField();
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

void MainWindow::drawCells() {
	int height = 2 * gameCore->getHeight();
	int width = 2 * gameCore->getWidth();
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			(i + j) % 2 ? glColor3ub(COLOR_CELL_BLACK) : glColor3ub(COLOR_CELL_WHITE);
			glBegin(GL_POLYGON);
			glVertex2i(i * width / FIELD_SIZE, j * height / FIELD_SIZE);
			glVertex2i(i * width / FIELD_SIZE, (j + 1) * height / FIELD_SIZE);
			glVertex2i((i + 1) * width / FIELD_SIZE, (j + 1) * height / FIELD_SIZE);
			glVertex2i((i + 1) * width / FIELD_SIZE, j * height / FIELD_SIZE);
			glEnd();
		}
	}

}
