#include "cuerpo.h"


Cuerpo::Cuerpo(float size){}



void Cuerpo::generaCuerpo(int partes,vector<_vertex3f> perfil){

    Vertices.resize(((perfil.size()-2)*partes) + 2);
    vector<_vertex3f> Centro;
    Centro.resize(2);
    int cont_res = 0;
    int cont_cent = 0;

    for(int i = 0; i < perfil.size(); i++){
        if(perfil[i]._0 != 0){
            for(int j = 0; j < partes; j++){
                    double part = j*(360/partes)*(M_PI/180);
                    float auxX = perfil[i]._0 * cos(part);
                    float auxZ = perfil[i]._0 * sin(part);
                    Vertices[cont_res++] = _vertex3f(auxX, perfil[i]._1, auxZ);
            }
        }
        else
            Centro[cont_cent++] = perfil[i];

    }

    for(int i = 0; i < Centro.size(); i++)
            Vertices[cont_res++] = _vertex3f(Centro[i].x, Centro[i].y, Centro[i].z);



}

void Cuerpo::generaCuerpoG(int partes,vector<_vertex3f> perfil, int eje){

    Vertices.resize(((perfil.size()-2)*partes) + 2);
    vector<_vertex3f> Centro;
    Centro.resize(2);
    int cont_res = 0;
    int cont_cent = 0;

    //ejey
    switch (eje) {
    case 0:{
        for(int i = 0; i < perfil.size(); i++){
            if(perfil[i]._0 != 0){
                for(int j = 0; j < partes; j++){
                        double part = j*(360/partes)*(M_PI/180);
                        float auxX = perfil[i]._0 * cos(part);
                        float auxZ = perfil[i]._0 * sin(part);
                        Vertices[cont_res++] = _vertex3f(auxX, perfil[i]._1, auxZ);
                }
            }
            else
                Centro[cont_cent++] = perfil[i];

        }

        for(int i = 0; i < Centro.size(); i++)
                Vertices[cont_res++] = _vertex3f(Centro[i].x, Centro[i].y, Centro[i].z);

    }break;

    //ejex
    case 1:{
        for(int i = 0; i < perfil.size(); i++){
            if(perfil[i]._1 != 0){
                for(int j = 0; j < partes; j++){
                        double part = j*(360/partes)*(M_PI/180);
                        float auxy = perfil[i]._0 * cos(part);
                        float auxZ = perfil[i]._0 * sin(part);
                        Vertices[cont_res++] = _vertex3f(perfil[i]._0, auxy, auxZ);
                }
            }
            else
                Centro[cont_cent++] = perfil[i];

        }

        for(int i = 0; i < Centro.size(); i++)
                Vertices[cont_res++] = _vertex3f(Centro[i].x, Centro[i].y, Centro[i].z);
    }break;

    //ejez
    case 2:{
        for(int i = 0; i < perfil.size(); i++){
            if(perfil[i]._1 != 0){
                for(int j = 0; j < partes; j++){
                        double part = j*(360/partes)*(M_PI/180);
                        float auxX = perfil[i]._1 * cos(part);
                        float auxy = perfil[i]._1 * sin(part);
                        Vertices[cont_res++] = _vertex3f(auxX, auxy, perfil[i]._2);
                }
            }
            else
                Centro[cont_cent++] = perfil[i];

        }

        for(int i = 0; i < Centro.size(); i++)
                Vertices[cont_res++] = _vertex3f(Centro[i].x, Centro[i].y, Centro[i].z);
    }break;

   }
}


void Cuerpo::generaPerfilEsfera(int partes,vector<_vertex3f> perfil){


    Vertices.resize(partes);
    int cont_res = 0;
    double grados = 180/partes;

    for(int j = 90; j >= 0 ; j = j - grados){
        double part = ((j)*(M_PI/180));
        float auxX = perfil[0]._1 * cos(part);
        float auxY = perfil[0]._1 * sin(part);
        if(auxX >= 0 && j !=90 || auxX <= 1 && auxX >= -1e-15 && j != 90){
            Vertices[cont_res++] = _vertex3f(auxX, auxY, perfil[0]._2 );
        }
    }

    for(int j = 360; j > 270 ; j = j - grados){
        double part = ((j)*(M_PI/180));
        float auxX = perfil[0]._1 * cos(part);
        float auxY = perfil[0]._1 * sin(part);
        if(auxX >= 0 || auxX <= 1 && auxX >= -1e-15){
            Vertices[cont_res++] = _vertex3f(auxX, auxY, perfil[0]._2 );
        }
    }



}

void Cuerpo::generaPerfilSemiEsfera(int partes, vector<_vertex3f> perfil){


    Vertices.resize(partes/2);
    int cont_res = 0;
    double grados = 180/partes;

    for(int j = 90; j >= 0 ; j = j - grados){
        double part = ((j)*(M_PI/180));
        float auxX = perfil[0]._1 * cos(part);
        float auxY = perfil[0]._1 * sin(part);
        if(auxX >= 0 && j !=90 || auxX <= 1 && auxX >= -1e-15 && j != 90){
            Vertices[cont_res++] = _vertex3f(auxX, auxY, Vertices[0]._2 );
        }
    }

}


void Cuerpo::generaTriangulos(int partes){

    int bases = (Vertices.size()-2)/partes;
    Triangles.resize((Vertices.size()-2)*2);
    int cont_tri = 0;

   for(int i = 0; i < partes; i++){

        Triangles[cont_tri++] =_vertex3ui(i,(i+1)%partes,Vertices.size()-2);

        for(int j = 1; j <bases; j++){
            Triangles[cont_tri++] = _vertex3ui(i+(partes*(j-1)),((i+1)%(partes))+((partes)*(j-1)) , i+(partes)+(partes*(j-1)));
            Triangles[cont_tri++] = _vertex3ui(i+partes+(partes*(j-1)),((i+1)%(partes))+partes+(partes*(j-1)),(i+1)%partes+(partes*(j-1)));
        }

        Triangles[cont_tri++] = _vertex3ui(((i+((bases-1)*partes))%(Vertices.size()-2)),(((i+1)%(partes))+partes*(bases-1))%(Vertices.size()-2),Vertices.size()-1);
    }

}

void Cuerpo::calculaNormales(){

    _vertex3f u, v, w;
     float longitud;
     vector<_vertex3f> aux;
    int ult = Vertices.size();


    NormalesVertices.resize(Vertices.size());
     for (unsigned int i = 0; i < Triangles.size(); i++){


         u( Vertices[Triangles[i]._1].x - Vertices[Triangles[i]._0].x
          , Vertices[Triangles[i]._1].y - Vertices[Triangles[i]._0].y
          , Vertices[Triangles[i]._1].z - Vertices[Triangles[i]._0].z );

         v( Vertices[Triangles[i]._2].x - Vertices[Triangles[i]._0].x
          , Vertices[Triangles[i]._2].y - Vertices[Triangles[i]._0].y
          , Vertices[Triangles[i]._2].z - Vertices[Triangles[i]._0].z );


        if(Vertices.size() < 1000)
            if(i%2 != 0){
                w((-u.y * v.z) - (-u.z * v.y)
                  ,-((-u.x * v.z) - (-u.z * v.x))
                  ,  (-u.x * v.y) - (-u.y * v.x));
            }
            else{
                w((u.y * v.z) - (u.z * v.y)
                ,-((u.x * v.z) - (u.z * v.x))
                ,  (u.x * v.y) - (u.y * v.x));
            }
        else{

            w((u.y * v.z) - (u.z * v.y)
            ,-((u.x * v.z) - (u.z * v.x))
            ,  (u.x * v.y) - (u.y * v.x));

        }

         longitud = sqrt( w.x*w.x + w.y*w.y + w.z*w.z );

         w.x /= longitud;
         w.y /= longitud;
         w.z /= longitud;



         Normales.push_back(w);
     }

     aux.resize(Vertices.size());

     for (unsigned int i = 0; i < Triangles.size(); i++){
         aux[Triangles[i]._0] += Normales[i];
         aux[Triangles[i]._1] += Normales[i];
         aux[Triangles[i]._2] += Normales[i];
     }

     for (unsigned int i = 0; i < aux.size(); i++){

         longitud = sqrt( pow(aux[i].x, 2) + pow(aux[i].y, 2) + pow(aux[i].z, 2) );

         NormalesVertices[i].x = aux[i].x/longitud;
         NormalesVertices[i].y = aux[i].y/longitud;
         NormalesVertices[i].z = aux[i].z/longitud;
     }

}


void Cuerpo::FlatShading() const{

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < Triangles.size(); i++){
        glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
        glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
        glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
        glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
    }

    glEnd();

}



void Cuerpo::GouraudShading() const{

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    for(int i = 0; i < Triangles.size(); i++){
        glNormal3f(NormalesVertices[Triangles[i]._0].x, NormalesVertices[Triangles[i]._0].y, NormalesVertices[Triangles[i]._0].z);
        glVertex3f(Vertices[Triangles[i]._0].x, Vertices[Triangles[i]._0].y, Vertices[Triangles[i]._0].z);
         glNormal3f(NormalesVertices[Triangles[i]._1].x, NormalesVertices[Triangles[i]._1].y, NormalesVertices[Triangles[i]._1].z);
        glVertex3f(Vertices[Triangles[i]._1].x, Vertices[Triangles[i]._1].y, Vertices[Triangles[i]._1].z);
         glNormal3f(NormalesVertices[Triangles[i]._2].x, NormalesVertices[Triangles[i]._2].y, NormalesVertices[Triangles[i]._2].z);
        glVertex3f(Vertices[Triangles[i]._2].x, Vertices[Triangles[i]._2].y, Vertices[Triangles[i]._2].z);
    }

    glEnd();

}

//gold
void Cuerpo::Material1() const{
    _vertex4f amb(0.24725, 0.1995, 0.0745, 1.0);
    _vertex4f diff(0.75164, 0.60648,0.22648, 1.0);
    _vertex4f spec(0.628281, 0.555802,0.366065, 1.0);
    float shine = 0.4;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  (GLfloat *) &amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  (GLfloat *) &diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &spec);
    glMaterialf(GL_FRONT, GL_SHININESS, shine*128.0);
    glPopMatrix();
}

//turquoise
void Cuerpo::Material2() const{
    _vertex4f amb(0.1, 0.18725, 0.1745, 1.0);
    _vertex4f diff(0.396, 0.74151,0.69102, 1.0);
    _vertex4f spec(0.297254, 0.30829,0.306678, 1.0);
    float shine = 0.1;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  (GLfloat *) &amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  (GLfloat *) &diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &spec);
    glMaterialf(GL_FRONT, GL_SHININESS, shine*128.0);
    glPopMatrix();
}

//obsidian
void Cuerpo::Material3() const{
    _vertex4f amb(0.05375, 0.05,0.06625, 1.0);
    _vertex4f diff(0.18275, 0.17,0.22525, 1.0);
    _vertex4f spec(0.332741, 0.328634,0.346435, 1.0);
    float shine = 0.3;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  (GLfloat *) &amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  (GLfloat *) &diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &spec);
    glMaterialf(GL_FRONT, GL_SHININESS, shine*128.0);
    glPopMatrix();
}
