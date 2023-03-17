#ifndef RECT_H
#define RECT_H

#include "SOIL/SOIL.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

void drawShape(int, float, float, float,float, float,float);


#endif // !RECT_H