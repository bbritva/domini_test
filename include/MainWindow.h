#ifndef DOMINI_TEST_MAINWINDOW_H
#define DOMINI_TEST_MAINWINDOW_H

class GameCore;
extern GameCore *gameCore;

class MainWindow {
private:
    int _windowDescriptor;

	static void drawMenu();
	static void drawGameField();
	static void drawCheckers();
	static void drawChecker(int i, int j, t_eCell cell);
	static void drawCells();
	static void drawButton(int y, std::string buttonName, t_eButton button);
	static void drawStrokeText(GLfloat y, const char *text);
	static void clickOnMenu(int keyCode, int keyState, int x, int y);
	static void clickOnGameField(int keyCode, int keyState, int x, int y);

	MainWindow();
	~MainWindow();

public:
	static void refresh();
	static void reshape(int height, int width);
	static void mouseClick(int a, int keyState, int x, int y);
	static void display();
};


#endif //DOMINI_TEST_MAINWINDOW_H
