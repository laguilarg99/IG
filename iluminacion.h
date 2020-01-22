#ifndef ILUMINACION_H
#define ILUMINACION_H

#include <iostream>
#include "object3d.h"
#include "vertex.h"

class Iluminacion
{
private:
    float ax, ay, az;
    float distance;

public:
    float ai;
    Iluminacion();
    void infinite();
    void near();
    void noinfinite() const;
    void nonear() const;
    void noiluminacion() const;
    void LuzX();
    void LuzY();
    void LuzZ();
    void LuzI();
    void Distanciasmas();
    void Distanciamenos();

};

#endif // ILUMINACION_H
