#ifndef MARIO_H
#define MARIO_H


#include "rect.h"

struct Mario {
    GLfloat x;
    GLfloat y;
    GLfloat sc;
    GLfloat vel;
    GLfloat grav;
    GLfloat texture_id;

    Mario(float, float, float, float, float);
    ~Mario();
    void draw(float,float);
};

#endif // MARIO_H
