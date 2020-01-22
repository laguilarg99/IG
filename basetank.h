#ifndef BASETANK_H
#define BASETANK_H

#include "object3d.h"
#include "cube.h"

class BaseTank: public _object3D
{
    public:
        BaseTank(float Size=1.0);
        void draw_fill();
        void draw_line();
        void draw_point();
};

#endif // BASETANK_H
