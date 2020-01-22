#include "semiesfera.h"

Semiesfera::Semiesfera(float Size)
{

    int partes = 60;

    vector<_vertex3f> perfil;
    vector<_vertex3f> aux;


    perfil.resize(1);
    perfil[0] = _vertex3f(0,Size,0);


    Cuerpo semicircunferencia;
    semicircunferencia.generaPerfilSemiEsfera(partes,perfil);
    semicircunferencia.Vertices.push_back(_vertex3f(0,Size,0));
    semicircunferencia.Vertices.push_back(_vertex3f(0,0,0));

    Cuerpo semiesfera;
    semiesfera.generaCuerpo(partes,semicircunferencia.Vertices);
    Vertices = semiesfera.Vertices;

    semiesfera.generaTriangulos(partes);
    Triangles = semiesfera.Triangles;

    this->calculaNormales();

}
