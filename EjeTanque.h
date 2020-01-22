#ifndef EJETANQUE_H
#define EJETANQUE_H


#include "object3d.h"
#include "Wheel.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class EjeTanque:public _object3D
{
    public:
      EjeTanque(float Size=1.0);
      void draw_fill(double giraRueda);
      void draw_line(double giraRueda);
      void draw_point(double giraRueda);
};

#endif // EJETANQUE_H
