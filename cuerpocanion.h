#ifndef CUERPOCANION_H
#define CUERPOCANION_H


#include "object3d.h"
#include "cilindro.h"

class Cuerpocanion: public _object3D
{
    public:
        Cuerpocanion(float Size=1.0);
        void draw_fill();
        void draw_line();
        void draw_point();
};


#endif // CUERPOCANION_H
