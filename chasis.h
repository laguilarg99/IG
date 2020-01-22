#ifndef CHASIS_H
#define CHASIS_H

#include "object3d.h"
#include "EjeTanque.h"
#include "basetank.h"

class chasis:public _object3D
{
public:
    chasis();
    void draw_fill(double giraRueda);
    void draw_line(double giraRueda);
    void draw_point(double giraRueda);
};

#endif // CHASIS_H
