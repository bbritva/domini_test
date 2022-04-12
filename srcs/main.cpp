
#include "main.h"

int main_w;

void drawText(GLfloat y, const char *text)
{

	glPushMatrix();
	glTranslatef(-30 * (float)strlen(text), y - 50, 0);
	glLineWidth(5);
	glScalef(1.5, 1.5, 1.5);
	for (int i = 0; text[i]; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	glPopMatrix();
}

void drawButton(int y, std::string buttonName)
{
	glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2f(-600 ,y + 150);
	glVertex2f(-600 ,y - 150);
	glVertex2f(600 ,y - 150);
	glVertex2f(600 ,y + 150);
	glEnd();
	glColor3ub(TEXT_COLOR);
	drawText(y, buttonName.c_str());
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

//	glLineWidth(10);
	//SetDisplayMode(MENU_SCREEN);

	drawButton(500, "Start game");
	drawButton(0, "Credits");
	drawButton(-500, "Exit");
	glutPostRedisplay();
	glFlush();
	glLoadIdentity();
	glutSwapBuffers();

}

void vis(int visState)
{
	printf("VIS: win=%d, v=%d\n", glutGetWindow(), visState);
}

//void reshape(int w, int h)
//{
//	int width = 50;
//	int height = 50;
//
//	glViewport(0, 0, w, h);
//	if (w > 50) {
//		width = (w - 3 * GAP) / 2;
//	} else {
//		width = 10;
//	}
//	if (h > 50) {
//		height = (h - 3 * GAP) / 2;
//	} else {
//		height = 10;
//	}
//	glutSetWindow(w1);
//	glutPositionWindow(GAP, GAP);
//	glutReshapeWindow(width, height);
//	glutSetWindow(w2);
//	glutPositionWindow(GAP + width + GAP, GAP);
//	glutReshapeWindow(width, height);
//	glutSetWindow(w3);
//	glutPositionWindow(GAP, GAP + height + GAP);
//	glutReshapeWindow(width, height);
//	glutSetWindow(w4);
//	glutPositionWindow(GAP + width + GAP, GAP + height + GAP);
//	glutReshapeWindow(width, height);
//}

void mouseClick(int a, int b, int x, int y)
{
	printf("a = %d, b = %d, x = %d, y = %d\n", a, b, x, y);
}

void init()
{
	glClearColor(0.0,0.0,0.0,0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-1200,1200,-1200,1200);                   //<-----CHANGE THIS TO GET EXTRA SPACE
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	main_w = glutCreateWindow(GAME_NAME);
	init();
	glutMouseFunc(mouseClick);
	glutVisibilityFunc(vis);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop();
	glutDestroyWindow(main_w);
	return 0;
}