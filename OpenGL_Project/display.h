#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h"
void goingUp(int);
void goingDown(int);

struct Display:public Game {
	Display();
	static void draw();
	void level();
	void run();
	Game* play;
	void motion();
	static void idle();
	~Display();
	static void keyboard(unsigned char , int, int);
	static void cont();
		
};

#endif // !DISPLAY_H
