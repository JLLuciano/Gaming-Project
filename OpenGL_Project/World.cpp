#include "World.h"

//#include "Textures.h"
#include <iostream>
using namespace std;

World::World(float x, float y, float x2, float y2) {
   
    //land.draw(1, x, y, x2, y2, 0);
    this->x = x;
    this->y = y;
    this->x2 = x2;
    this->y2 = y2;
    this->grav = 0.0;
    this->texture_id = SOIL_load_OGL_texture(
        "images/PlatBrick.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB
    );;
    //draw();
}
void World::draw() {
    drawShape(1,x,y,x2,y2,grav,texture_id);
}


World::~World() { 
    delete this;
}