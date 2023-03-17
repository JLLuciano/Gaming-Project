#include "display.h"

static Display* display;


void goingUp(int time) {
    if (display->play->grav < 0.35 && display->play->jump && display->play->up and !display->play->down) {
        display->play->grav += 0.05; 
        if (display->play->vel < display->play->vel2) {
            display->play->vel -= 0.01;
        }
        else if (display->play->vel > display->play->vel2){
            display->play->vel += 0.01;
        }
        else {
            display->play->vel += 0.0;
        }
        display->play->landy = display->play->good->y - display->play->good->sc + display->play->grav; 
       glutTimerFunc(30, goingUp, 0);
 
    }
    else {
        display->play->up = false;
        display->play->down = true;
        display->play->jump = false;
    }
   
}
void goingDown(int time) {
    if (time == 0 and display->play->landy > -0.5) {
        if (display->play->landy >= -0.5) {
            display->play->grav -= 0.01;
            if (display->play->vel < display->play->vel2) {
                display->play->vel -= 0.005;
            }
            else {
                display->play->vel += 0.005;
            }
            display->play->landy = display->play->good->y - display->play->good->sc + display->play->grav;   
        }
    }
       
    if(time == 1 and display->play->down) {
        display->play->jump = false;
        if (display->play->landy <= -1.05) {
            exit(0);
        }
        display->play->grav -= 0.01;
        if (display->play->vel < display->play->vel2) {
            display->play->vel -= 0.005;
        }
        else {
            display->play->vel += 0.005;
        }
        display->play->landy = display->play->good->y - display->play->good->sc + display->play->grav;
   
    }
  
}


void Display::keyboard(unsigned char c, int x, int y) {
    if (c == 27) {
        display->~Display();
        exit(0);
    }
    switch (c)
    {
    case GLUT_KEY_LEFT:
        display->play->vel2 = display->play->vel;
        display->play->vel -= 0.01;  
        break;
    case GLUT_KEY_RIGHT:
        display->play->vel2 = display->play->vel;
        display->play->vel += 0.01;
        break;          
    case GLUT_KEY_UP:
        display->play->up = true;
        goingUp(0);
        break;                
    }
}

Display::Display(): Game(1){
    display = this;

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Mario");
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(draw); 
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display->idle);
    glutMouseFunc(mouse);
    display->play = new Game(0);
}

void Display::level(){
}
void Display::run() {
    glutMainLoop();
}
void lrWalk(int time) {
    if (display->play->touch(display->play->good, display->play->bad)) {
        exit(0);
    }
    if (display->play->vel3 > 0.05) {
        display->play->right = false;
    }
    if (display->play->vel3 < -0.05) {
        display->play->right = true;
    }
    if (display->play->right) {
        display->play->vel3 += 0.005;
    }
    else {
        display->play->vel3 -= 0.005;
    }
    glutPostRedisplay();
   
}
void Display::idle() {
    display->motion();
    lrWalk(0); 
    glutPostRedisplay();    
}

void Display::draw() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    display->cont(); 
    glutSwapBuffers();
    glFlush();
}
void Display::motion() {
    if((display->play->checkPos(display->play->good, display->play->plat)) and !display->play->up and (display->play->checkPos(display->play->good, display->play->plat2))){
        display->play->down = true;
        goingDown(1);
    }
    if ((display->play->checkH(display->play->good, display->play->plat)) and display->play->down and !display->play->up) {
        goingDown(0);
    }
    if (!(display->play->checkH(display->play->good, display->play->plat))) {
        if ((display->play->checkPos(display->play->good, display->play->plat)) and (display->play->checkPos(display->play->good, display->play->plat2))) {
            display->play->jump = false;
        }
        else {
            display->play->down = false;
            display->play->jump = true;
        }
    }
   
}
void Display::cont() {
    display->play->good->draw(display->play->vel, display->play->grav);
    display->play->bad->draw(display->play->vel3);  
    display->play->plat->draw();
    display->play->plat2->draw();
    display->play->back->draw();
}
Display::~Display() {
    delete this;
}
