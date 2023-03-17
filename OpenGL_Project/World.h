#ifndef WORLD_H
#define WORLD_H

#include "SOIL/SOIL.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <vector>
#include "rect.h"

struct World {
    
	float x;
	float x2;
	float y;
	float y2;
	float grav;
	float texture_id;
	World(float, float, float, float);
	~World();
	void draw();

};

#endif
