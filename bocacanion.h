#ifndef BOCACANION_H
#define BOCACANION_H

#include "object3d.h"
#include "cilindro.h"

class Bocacanion: public _object3D
{
    public:
        Bocacanion(float Size=1.0);
        void draw_fill(double third_degree);
        void draw_line(double third_degree);
        void draw_point(double third_degree);
};


#endif // BOCACANION_H
