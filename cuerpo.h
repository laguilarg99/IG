#ifndef CUERPO_H
#define CUERPO_H

#include <iostream>
#include <cmath>
#include "basic_object3d.h"
#include "object3d.h"
#include "colors.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


class Cuerpo:public _object3D
{

public:
    vector<_vertex3f> Normales;
    vector<_vertex3f> NormalesVertices;

    Cuerpo(const float size = 1.0);
    void generaCuerpo(int partes,vector<_vertex3f> perfil);
    void generaCuerpoG(int partes,vector<_vertex3f> perfil, int eje);
    void generaPerfilEsfera(int partes,vector<_vertex3f> perfil);
    void generaPerfilSemiEsfera(int partes,vector<_vertex3f> perfil);
    void generaTriangulos(int partes);
    void calculaNormales();
    void FlatShading() const;
    void GouraudShading() const;
    void Material1() const;
    void Material2() const;
    void Material3() const;
};

#endif // CUERPO_H
