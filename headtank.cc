#include "headtank.h"

HeadTank::HeadTank(float Size)
{

}

void HeadTank::draw_fill(double second_degree, double third_degree){

    Semiesfera semiesfera;
    canion canon;
    float angulo = second_degree *(M_PI/180);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(1.5,1.5,1.5);
    glColor3f(0,0.4,0);
    semiesfera.draw_fill();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-sin(angulo)-sin(angulo)+1.7,cos(angulo)+cos(angulo));
    glRotatef(second_degree, 1,0,0);
    canon.draw_fill(third_degree);
    glPopMatrix();


}

void HeadTank::draw_line(double second_degree, double third_degree){

    Semiesfera semiesfera;
    canion canon;
    float angulo = second_degree *(M_PI/180);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(1.5,1.5,1.5);
    glColor3f(0,0.4,0);
    semiesfera.draw_line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-sin(angulo)-sin(angulo)+1.7,cos(angulo)+cos(angulo));
    glRotatef(second_degree, 1,0,0);
    canon.draw_line(third_degree);
    glPopMatrix();


}

void HeadTank::draw_point(double second_degree, double third_degree){

    Semiesfera semiesfera;
    canion canon;
    float angulo = second_degree *(M_PI/180);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,1.25,0);
    glScalef(1.5,1.5,1.5);
    glColor3f(0,0.4,0);
    semiesfera.draw_point();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-sin(angulo)-sin(angulo)+1.7,cos(angulo)+cos(angulo));
    glRotatef(second_degree, 1,0,0);
    canon.draw_point(third_degree);
    glPopMatrix();


}


