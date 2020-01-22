#include "panel.h"

panel::panel(float Size)
{
    //int partes = 12;
    //int puntos = 14;

    int partes = 4;
    int puntos = 6;

   generaPanel(puntos, partes);
   generaTriangulosPanel(partes);
   this->calculaNormales();
}


void panel::generaPanel(int puntos, int partes){

    vector <_vertex3f> base;

    float inix = -(puntos/2);
    float iniy = -(partes/2);
    float iniz1 = 0.005;
    float iniz2 = -0.005;

    int cont_res = 0;

    for(int i = 0; i <= puntos; i++){
        base.push_back(_vertex3f(inix+i,iniy, iniz1));
        base.push_back( _vertex3f(inix+i,iniy, iniz2));
    }

    for(int i = 0; i < base.size(); i++){
        for(int j = 0; j <= partes; j++){
            float auxy = base[i].y++;
            Vertices.push_back(_vertex3f(base[i].x, auxy, base[i].z));
        }
    }



}

void panel::generaTriangulosPanel(int partes){


    for(int i=0; i < Vertices.size()- (5 + partes); i+=(partes+1)){
        for(int j = 0, z = i; j < partes; j++){
            Triangles.push_back(_vertex3ui(z, z+(partes*2)+2,z+1));
            Triangles.push_back(_vertex3ui(z+1, z+1+(partes*2)+2,z+(partes*2)+2));
            z++;
        }
    }
}
