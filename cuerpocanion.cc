#include "cuerpocanion.h"

Cuerpocanion::Cuerpocanion(float Size)
{

}

void Cuerpocanion::draw_fill(){
    cilindro canion;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.3,1.5,0.3);
    glColor3f(0,0.1,0);
    canion.draw_fill();
    glPopMatrix();

}

void Cuerpocanion::draw_line(){
    cilindro canion;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.3,1.5,0.3);
    glColor3f(0,0.1,0);
    canion.draw_line();
    glPopMatrix();

}

void Cuerpocanion::draw_point(){
    cilindro canion;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.3,1.5,0.3);
    glColor3f(0,0.1,0);
    canion.draw_point();
    glPopMatrix();

}
