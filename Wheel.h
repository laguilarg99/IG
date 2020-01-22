#ifndef WHEEL_H
#define WHEEL_H

#include "object3d.h"
#include "cilindro.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class Wheel:public _object3D
{
    public:
      Wheel(float Size=1.0);
      void draw_fill(double giraRueda);
      void draw_line(double giraRueda);
      void draw_point(double giraRueda);
};

#endif // WHEEL_H
