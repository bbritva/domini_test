//
// Created by bbritva on 11.04.2022.
//

#ifndef DOMINI_TEST_MAINWINDOW_H
#define DOMINI_TEST_MAINWINDOW_H

#include "main.h"

typedef enum e_State {
	MENU,
	GAME,
	GAME_MOVE_POSSIBILITIES,
	GAME_MOVING,
	END_GAME
} t_eState;

class MainWindow {
private:

	int *_argc;
	char **_argv;
    int _windowDescriptor;
	t_eState _state;

	static void display();
	static void drawButton(int y, std::string buttonName);
	static void drawStrokeText(GLfloat y, const char *text);
	static void refresh();
	static void mouseClick(int a, int b, int x, int y);


public:
	MainWindow(int *argc, char **argv);
    ~MainWindow();

	int start();
};


#endif //DOMINI_TEST_MAINWINDOW_H
