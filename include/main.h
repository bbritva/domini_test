//
// Created by bbritva on 11.04.2022.
//

#ifndef DOMINI_TEST_MAIN_H
#define DOMINI_TEST_MAIN_H

#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "typedefs.h"
#include "MainWindow.h"
#include "GameCore.h"

#define GAME_NAME "Domini Corners"
#define BUTTON_COLOR 255,0,0
#define BUTTON_PRESSED_COLOR 0,255,0
#define TEXT_COLOR 0,0,0
#define WINDOW_HEIGHT 1200
#define WINDOW_WIDTH 1200
#define GLU_ORTO_HEIGHT 2400
#define GLU_ORTO_WIDTH 2400
#define LEFT_MOUSE_BUTTON 0

void addEventHandlers();
int init(int *argc, char **argv);

#endif //DOMINI_TEST_MAIN_H
