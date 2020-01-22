/*! \file
 * Copyright Luis Miguel Aguilar González
 */


#ifndef ESFERA_H
#define ESFERA_H

#include "object3d.h"
#include "cuerpo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


class esfera:public Cuerpo
{

public:
    esfera(float Size=1.0);
};

#endif // ESFERA_H
