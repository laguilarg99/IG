#include "chasis.h"

chasis::chasis()
{

}

void chasis::draw_fill(double giraRueda){

    EjeTanque eje1, eje2, eje3, eje4;
    BaseTank base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,3);
    eje1.draw_fill(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,1);
    eje2.draw_fill(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje3.draw_fill(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-3);
    eje4.draw_fill(giraRueda);
    glPopMatrix();
    glPushMatrix();
    base.draw_fill();
    glPopMatrix();

}

void chasis::draw_line(double giraRueda){

    EjeTanque eje1, eje2, eje3, eje4;
    BaseTank base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,3);
    eje1.draw_line(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,1);
    eje2.draw_line(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje3.draw_line(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-3);
    eje4.draw_line(giraRueda);
    glPopMatrix();
    glPushMatrix();
    base.draw_line();
    glPopMatrix();

}

void chasis::draw_point(double giraRueda){

    EjeTanque eje1, eje2, eje3, eje4;
    BaseTank base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,0,3);
    eje1.draw_point(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,1);
    eje2.draw_point(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-1);
    eje3.draw_point(giraRueda);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-3);
    eje4.draw_point(giraRueda);
    glPopMatrix();
    glPushMatrix();
    base.draw_point();
    glPopMatrix();

}

