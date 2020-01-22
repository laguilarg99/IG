/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "object3d.h"
#include "cuerpo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _tetrahedron:public Cuerpo
{
public:
  _tetrahedron(float Size=1.0);
};

#endif
