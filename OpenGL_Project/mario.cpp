#include "mario.h"

#include <iostream>

Mario::Mario(float x, float y, float r, float vel, float grav) {
    this->x = x;
    this->y = y;
    this->sc = r;
    this->vel = vel;
    this->grav = grav;
    this-> texture_id = SOIL_load_OGL_texture(
        "images/PlatBrick.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB
    );
  
}
Mario::~Mario() {
    //delete mario;
}
void Mario::draw(float v, float g) {
    drawShape(0,x,y,sc,v,g,texture_id);
}

