#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "rect.h"

struct Background {

    GLfloat texture_id;
    Background();
    //~background();
    void draw();
};

#endif // BACKGROUND_H
