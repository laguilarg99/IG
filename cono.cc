#include "cono.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

cono::cono(float Size)
{
    int partes = 30;

    vector<_vertex3f> perfil;

//ejey = 0
    perfil.resize(3);
    perfil[0] = _vertex3f(0,Size,0);
    perfil[1] = _vertex3f(0,-Size,0);
    perfil[2] = _vertex3f(Size,-Size,0);

//ejex = 1
//    perfil.resize(3);
//    perfil[0] = _vertex3f(Size,0,0);
//    perfil[1] = _vertex3f(-Size,0,0);
//    perfil[2] = _vertex3f(Size,Size,0);

//ejez = 2
//    perfil.resize(3);
//    perfil[0] = _vertex3f(0,0,Size);
//    perfil[1] = _vertex3f(0,0,-Size);
//    perfil[2] = _vertex3f(0,Size,-Size);

    Cuerpo cono;

    cono.generaCuerpo(partes,perfil);
//  cono.generaCuerpoG(partes,perfil,2);
    Vertices = cono.Vertices;

    cono.generaTriangulos(partes);
    Triangles = cono.Triangles;

    this->calculaNormales();
}
