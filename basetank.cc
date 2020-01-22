#include "basetank.h"


BaseTank::BaseTank(float Size)
{


}

void BaseTank::draw_fill(){
    _cube base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(3.4,0.5,7);
    glColor3f(0,0.3,0);
    base.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glScalef(3.4,0.5,6.5);
    glColor3f(0,0.3,0);
    base.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,-3.1);
    glRotatef(75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,3.1);
    glRotatef(-75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_fill();
    glPopMatrix();


}

void BaseTank::draw_line(){
    _cube base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(3.4,0.5,7);
    glColor3f(0,0.3,0);
    base.draw_line();
    glPopMatrix();
    glPushMatrix();
    glScalef(3.4,0.5,6.5);
    glColor3f(0,0.3,0);
    base.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,-3.1);
    glRotatef(75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,3.1);
    glRotatef(-75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_line();
    glPopMatrix();


}

void BaseTank::draw_point(){
    _cube base;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1,0);
    glScalef(3.4,0.5,7);
    glColor3f(0,0.3,0);
    base.draw_point();
    glPopMatrix();
    glPushMatrix();
    glScalef(3.4,0.5,6.5);
    glColor3f(0,0.3,0);
    base.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,-3.1);
    glRotatef(75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,3.1);
    glRotatef(-75,1,0,0);
    glScalef(3.4,0.5,1);
    glColor3f(0,0.3,0);
    base.draw_point();
    glPopMatrix();

}
