#include "goomba.h"
#include <iostream>
Goomba::Goomba(float x, float y, float r, float vel, float grav){
    this->x = x;
    this->y = y;
    this->sc = r;
    this->vel = vel;
    this->grav = grav;
    this ->texture_id = SOIL_load_OGL_texture(
        "images/goomba.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB
    );
   
}
void Goomba::draw(float move) {
    drawShape(0,x,y,sc,move,grav,texture_id);
}
Goomba::~Goomba() {
    //Goomba obj = this;
    delete this;
}
