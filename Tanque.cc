///*! \file
// * Copyright Luis Miguel Aguilar González
// */


#include "Tanque.h"


///*****************************************************************************//**
// *
// *
// *
// *****************************************************************************/

Tanque::Tanque(float Size)
{
}

void Tanque::_draw_fill(double first_degree, double second_degree, double third_degree, double giraRueda){

    chasis chasis;
    HeadTank Torreta;

    glMatrixMode(GL_MODELVIEW);
    chasis.draw_fill(giraRueda);
    glPushMatrix();
    glRotatef(first_degree,0,1,0);
    Torreta.draw_fill(second_degree,third_degree);
    glPopMatrix();


}

void Tanque::_draw_line(double first_degree, double second_degree, double third_degree, double giraRueda){

    chasis chasis;
    HeadTank Torreta;

    glMatrixMode(GL_MODELVIEW);
    chasis.draw_line(giraRueda);
    glPushMatrix();
    glRotatef(first_degree,0,1,0);
    Torreta.draw_line(second_degree,third_degree);
    glPopMatrix();


}

void Tanque::_draw_point(double first_degree, double second_degree, double third_degree, double giraRueda){

    chasis chasis;
    HeadTank Torreta;

    glMatrixMode(GL_MODELVIEW);
    chasis.draw_point(giraRueda);
    glPushMatrix();
    glRotatef(first_degree,0,1,0);
    Torreta.draw_point(second_degree,third_degree);
    glPopMatrix();


}




