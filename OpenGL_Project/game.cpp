#include "game.h"

Game::Game(int x) {
    if (x == 0) {
        std::cout << "make" << std::endl;
        load();
    }
}

void Game::load() {
    plat = new World(-1, -1, -0.2, -0.5);//(x,y,x2,y2)
    plat2 = new World(0, -1, 1, -0.5);
    good = new Mario(-0.95, -0.47, 0.03, 0.0, 0.0);//vel and grav will update and will change position character
    bad = new Goomba(0.3, -0.45, 0.05, vel3, 0);
    back = new Background();
}
void Game::run() {
    //lrWalk(0);
}


bool Game:: checkPos(Mario* obj, World* obj2) {//check if mario is on platform

    if ((obj->x + vel - 0.03) < (obj2->x - 0.005) || (obj2->x2 + 0.005) < (obj->x + vel + 0.03)) {
        return true;
    }
    else {
       return false;
    }
}
bool Game::checkH(Mario* obj, World* obj2) {
   // std::cout << obj2->y2 << std::endl;
    if ((obj->y - obj->sc + grav) > obj2->y2) {
        return true;
    }
    else {
        return false;
    }
}
bool Game::touch(Mario* obj, Goomba* obj2) {
    if ((obj->x + vel) >= (obj2->x - 0.05 + vel3) && (obj->x + vel) <= (obj2->x + 0.05 + vel3) && (obj->y - obj->sc + grav) >= (obj2->y - obj2->sc-0.05) && (obj->y + obj->sc + grav) <= (obj2->y + obj2->sc)) {
        return true;
    }
    else {
        return false;
    }
}


void Game::mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        exit(0);
    }
}