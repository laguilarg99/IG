#include "EjeTanque.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

EjeTanque::EjeTanque(float Size)
{



}

void EjeTanque::draw_fill(double giraRueda){

    cilindro eje;
    Wheel rueda1;
    Wheel rueda2;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.2,2,0.2);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    eje.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    rueda1.draw_fill(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    rueda2.draw_fill(giraRueda);
    glPopMatrix();

}

void EjeTanque::draw_line(double giraRueda){

    cilindro eje;
    Wheel rueda1;
    Wheel rueda2;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.2,2,0.2);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    eje.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    rueda1.draw_line(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    rueda2.draw_line(giraRueda);
    glPopMatrix();

}

void EjeTanque::draw_point(double giraRueda){

    cilindro eje;
    Wheel rueda1;
    Wheel rueda2;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.2,2,0.2);
    glColor3fv((GLfloat *) & _colors_ne::BLACK);
    eje.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    rueda1.draw_point(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    rueda2.draw_point(giraRueda);
    glPopMatrix();

}
