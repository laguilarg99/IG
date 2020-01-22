/*! \file
 * Copyright Luis Miguel Aguilar González
 */


#include "cilindro.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

cilindro::cilindro(float Size)
{
    int partes = 30;


    vector<_vertex3f> perfil;

    perfil.resize(4);
    perfil[0] = _vertex3f(Size,Size,0);
    perfil[1] = _vertex3f(0,Size,0);
    perfil[2] = _vertex3f(0,-Size,0);
    perfil[3] = _vertex3f(Size,-Size,0);

    Cuerpo cilindro;

    cilindro.generaCuerpo(partes,perfil);
    Vertices = cilindro.Vertices;

    cilindro.generaTriangulos(partes);
    Triangles = cilindro.Triangles;

    this->calculaNormales();


}
