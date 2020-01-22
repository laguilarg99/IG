#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "cuerpo.h"
#include "cube.h"
#include <QImage>
#include <QImageReader>
#include <QMessageBox>
#include <QGuiApplication>
#include <QDir>
#include "panel.h"
#include "cilindro.h"
#include "esfera.h"

class chess_board:public Cuerpo
{
private:
    panel pantalla;
    QImage image;
    cilindro cil;
    esfera sphere;
public:
    chess_board();
    void translate() const;
    void draw_tablero();
    void drawPanel();
    void drawCilindro();
    void drawSphere();
    void load();
};

#endif // CHESS_BOARD_H
