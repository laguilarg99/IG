#include "bocacanion.h"

Bocacanion::Bocacanion(float Size)
{

}

void Bocacanion::draw_fill(double third_degree){
    cilindro telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,third_degree+1.5);
    glRotatef(90,1,0,0);
    glScalef(0.35,0.5,0.35);
    glColor3f(0,0.6,0);
    telescopio.draw_fill();
    glPopMatrix();
}

void Bocacanion::draw_line(double third_degree){
    cilindro telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,third_degree+1.5);
    glRotatef(90,1,0,0);
    glScalef(0.35,0.5,0.35);
    glColor3f(0,0.6,0);
    telescopio.draw_line();
    glPopMatrix();
}


void Bocacanion::draw_point(double third_degree){
    cilindro telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,third_degree+1.5);
    glRotatef(90,1,0,0);
    glScalef(0.35,0.5,0.35);
    glColor3f(0,0.6,0);
    telescopio.draw_point();
    glPopMatrix();
}

