#include "esfera.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

esfera::esfera(float Size)
{
    int partes = 30;

    vector<_vertex3f> perfil;
    vector<_vertex3f> aux;


    perfil.resize(1);
    perfil[0] = _vertex3f(0,Size,0);


    Cuerpo semicircunferencia;
    semicircunferencia.generaPerfilEsfera(partes,perfil);
    semicircunferencia.Vertices.push_back(_vertex3f(0,Size,0));
    semicircunferencia.Vertices.push_back(_vertex3f(0,-Size,0));

    Cuerpo esfera;
    esfera.generaCuerpo(partes,semicircunferencia.Vertices);
    Vertices = esfera.Vertices;

    esfera.generaTriangulos(partes);
    Triangles = esfera.Triangles;





    this->calculaNormales();

}
