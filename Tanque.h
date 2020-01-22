#ifndef TANQUE_H
#define TANQUE_H


#include "object3d.h"
#include "colors.h"
#include "EjeTanque.h"
#include "Wheel.h"
#include "chasis.h"
#include "basetank.h"
#include "headtank.h"
#include "canion.h"
#include "QTimer"
#include "QObject"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class Tanque:public _object3D
{
    public:
      Tanque(float Size=1.0);
      void _draw_fill(double first_degree, double second_degree, double third_degree, double giraRueda);
      void _draw_point(double first_degree, double second_degree, double third_degree, double giraRueda);
      void _draw_line(double first_degree, double second_degree, double third_degree, double giraRueda);
};

#endif // TANQUE_H
