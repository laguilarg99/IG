/*! \file
 * Copyright Luis Miguel Aguilar González
 */


#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H

#include<iostream>
#include "file_ply_stl.h"
#include"object3d.h"
#include"cuerpo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class Object_Ply:public Cuerpo
{
public:
    Object_Ply(float Size=1.0);
};

#endif // OBJECT_PLY_H
