#ifndef GOOMBA_H
#define GOOMBA_H

#include "rect.h"

struct Goomba{
    GLfloat x;
    GLfloat y;
    GLfloat sc;
    GLfloat vel;
    GLfloat grav;
    GLfloat texture_id;
    Goomba(float, float, float, float, float);
    void draw(float move);
    ~Goomba();

};
#endif