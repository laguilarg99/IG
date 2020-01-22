#include "canion.h"

canion::canion(float Size)
{


}

void canion::draw_fill(double third_degree){
    Cuerpocanion canion;
    Bocacanion telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    canion.draw_fill();
    glPopMatrix();
    glPushMatrix();
    telescopio.draw_fill(third_degree);
    glPopMatrix();

}

void canion::draw_line(double third_degree){
    Cuerpocanion canion;
    Bocacanion telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    canion.draw_line();
    glPopMatrix();
    glPushMatrix();
    telescopio.draw_line(third_degree);
    glPopMatrix();

}

void canion::draw_point(double third_degree){
    Cuerpocanion canion;
    Bocacanion telescopio;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    canion.draw_point();
    glPopMatrix();
    glPushMatrix();
    telescopio.draw_point(third_degree);
    glPopMatrix();

}
