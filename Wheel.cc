/*! \file
 * Copyright Luis Miguel Aguilar González
 */


#include "Wheel.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

Wheel::Wheel(float Size)
{

}

void Wheel::draw_fill(double giraRueda){

    cilindro rueda;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,1,1);
    glRotatef(giraRueda,1,0,0);
    glRotatef(90,0,0,1);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    rueda.draw_chess();
    glPopMatrix();
}

void Wheel::draw_line(double giraRueda){

    cilindro rueda;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,1,1);
    glRotatef(giraRueda,1,0,0);
    glRotatef(90,0,0,1);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    rueda.draw_line();
    glPopMatrix();

}

void Wheel::draw_point(double giraRueda){

    cilindro rueda;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,1,1);
    glRotatef(giraRueda,1,0,0);
    glRotatef(90,0,0,1);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    rueda.draw_point();
    glPopMatrix();
}




