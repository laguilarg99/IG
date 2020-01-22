#ifndef HEADTANK_H
#define HEADTANK_H

#include "object3d.h"
#include "basetank.h"
#include "canion.h"
#include "semiesfera.h"
#include "cube.h"

class HeadTank:public _object3D
{
    public:
        HeadTank(float Size=1.0);
        void draw_fill(double second_degree, double third_degree);
        void draw_line(double second_degree, double third_degree);
        void draw_point(double second_degree, double third_degree);
};

#endif // HEADTANK_H
