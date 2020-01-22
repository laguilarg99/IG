#ifndef CANION_H
#define CANION_H

#include "object3d.h"
#include "cilindro.h"
#include "bocacanion.h"
#include "cuerpocanion.h"


class canion: public _object3D
{
    public:
        canion(float Size=1.0);
        void draw_fill(double third_degree);
        void draw_line(double third_degree);
        void draw_point(double third_degree);
};

#endif // CANION_H
