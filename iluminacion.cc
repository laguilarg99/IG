#include "iluminacion.h"

Iluminacion::Iluminacion()
{
    ax = 0.0;
    ay = 0.0;
    az = 0.0;
    ai = 0.0;
    distance = 10.0;
}

void Iluminacion::infinite(){
    GLfloat luz_ambiente [] = {0.3, 0.3, 0.3, 0.0};
    GLfloat zero [] = {0,0,0,0};
       glEnable (GL_LIGHTING);
       glLightfv(GL_LIGHT0, GL_SPECULAR, luz_ambiente);
       glEnable (GL_LIGHT0);

       GLfloat pos1[] = {distance, distance, distance, 1};
       glPushMatrix();
       glRotatef(az, 0, 0, 1);
       glRotatef(ax, 1, 0, 0);
       glRotatef(ay, 0, 1, 0);
       glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, zero);
       glLightfv(GL_LIGHT0, GL_POSITION, pos1);

       glPopMatrix();
}

void Iluminacion::near(){
    GLfloat luz [] = {1,1,1,1};

    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,luz);
    glEnable(GL_LIGHT1);
    float red[] = { 0.5, 0, 0, 1 };

    GLfloat pos1[] = {distance, distance, distance, 1};

    glPushMatrix();
    glRotatef(ai,0,1,0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, red);
    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
    glPopMatrix();

}

void Iluminacion::noinfinite() const {
    glDisable(GL_LIGHT0);
}

void Iluminacion::nonear() const {
    glDisable(GL_LIGHT1);

}


void Iluminacion::noiluminacion() const {
    glDisable(GL_LIGHTING);

}
void Iluminacion::LuzX(){
    ax += 15;
    ax == 360.0?:ax = 0.0;
}


void Iluminacion::LuzY(){
    ay += 15;
    ay == 360.0?:ay = 0.0;
}


void Iluminacion::LuzZ(){
    az += 15;
    az == 360.0?:az = 0.0;
}


void Iluminacion::LuzI(){
    ai += 15;
    ai == 360.0?:ai = 0.0;
}

void Iluminacion::Distanciasmas(){
    distance += 0.1;
}

void Iluminacion::Distanciamenos(){
    distance -= 0.1;
}
