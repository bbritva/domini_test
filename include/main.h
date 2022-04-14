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
#define TEXT_COLOR 0,0,0
#define HEIGHT 1024
#define WIDTH 1024

void addEventHandlers();
int init(int *argc, char **argv);

#endif //DOMINI_TEST_MAIN_H
