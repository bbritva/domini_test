#include "main.h"

int main_w;

void displayRasterText(float x ,float y ,float z ,const char *stringToDisplay) {

	glRasterPos3f(x, y, z);
	for(char* c = const_cast<char *>(stringToDisplay); *c != '\0'; c++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
	}
}

void drawButton(int y)
{
	glColor3ub(BUTTON_COLOR);
	glBegin(GL_POLYGON);               //Border
	glVertex2f(-600 ,y + 150);
	glVertex2f(-600 ,y - 150);
	glVertex2f(600 ,y - 150);
	glVertex2f(600 ,y + 150);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

//	glLineWidth(10);
	//SetDisplayMode(MENU_SCREEN);

	std::string str = "fff";
	drawButton(-500);
	drawButton(0);
	drawButton(500);
	glColor3ub(255,255,255);
	displayRasterText(0,0,0, str.c_str());
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