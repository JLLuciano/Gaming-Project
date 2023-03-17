#include "rect.h"

void drawShape(int type, float x, float y, float sc, float vel, float grav, float texture_id) {
    if (type == 0) {//creating our mario
       
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glEnable(GL_TEXTURE_2D); 
        
        glColor4f(1.0, 1.0, 1.0, 1.0);
       // glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex2f(x - sc + vel, y - sc + grav);

        glTexCoord2f(0, 1);
        glVertex2f(x - sc + vel, y + sc + grav);

        glTexCoord2f(1, 1);
        glVertex2f(x + sc + vel, y + sc + grav);

        glTexCoord2f(1, 0);
        glVertex2f(x + sc + vel, y - sc + grav);
 
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    if(type == 1) {//platform
        //sc -> x2
        //vel-> y2
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glEnable(GL_TEXTURE_2D);
        glColor4f(1.0, 1.0, 1.0, 1.0);
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex2f(x,y);

        glTexCoord2f(0, 1);
        glVertex2f(x, vel);

        glTexCoord2f(1, 1);
        glVertex2f(sc, vel);

        glTexCoord2f(1, 0);
        glVertex2f(sc,y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
 
    }
    if (type == 2) {
        //this is for initializing purposes, want to avoid making more objects
    }
};



