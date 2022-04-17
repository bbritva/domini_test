#ifndef DOMINI_TEST_MAIN_H
#define DOMINI_TEST_MAIN_H

#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "typedefs.h"
#include "GameField.h"
#include "MainWindow.h"
#include "AIPlayer.h"
#include "GameCore.h"

void addEventHandlers();
int init(int *argc, char **argv);

#endif //DOMINI_TEST_MAIN_H
