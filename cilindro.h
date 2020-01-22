/*! \file
 * Copyright Luis Miguel Aguilar González
 */


#ifndef CILINDRO_H
#define CILINDRO_H

#include "object3d.h"
#include "cuerpo.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


class cilindro:public Cuerpo
{
public:
    cilindro(float Size=1.0);
};

#endif // CILINDRO_H
