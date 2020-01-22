/*! \file
 * Copyright Luis Miguel Aguilar González
 */



#ifndef CUBO_H
#define CUBO_H

#include "object3d.h"
#include "cuerpo.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cube:public Cuerpo
{
public:
  _cube(float Size=1.0);
};

#endif // CUBO_H
