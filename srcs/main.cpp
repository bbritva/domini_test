#include "main.h"

__attribute__((unused)) int main_w;

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(100 ,300);
	glVertex2f(100 ,400);
	glVertex2f(200 ,400);
	glVertex2f(200 ,300);
	glEnd();
	glFlush();
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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	main_w = glutCreateWindow("4 subwindows");
	glutMouseFunc(mouseClick);
	glutDisplayFunc(display);
	glutVisibilityFunc(vis);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMainLoop();
	return 0;
}