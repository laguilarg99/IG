#ifndef PANEL_H
#define PANEL_H

#include "cuerpo.h"

class panel:public Cuerpo
{
public:
    panel(float Size=1.0);
    void generaPanel(int puntos, int partes);
    void generaTriangulosPanel(int partes);
};

#endif // PANEL_H
