/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <GL/freeglut.h>
#include <QTimer>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cilindro.h"
#include "cono.h"
#include "cube.h"
#include "esfera.h"
#include "object_ply.h"
#include "cuerpo.h"
#include "Tanque.h"
#include "iluminacion.h"
#include "chess_board.h"
#include "panel.h"
#include <QMouseEvent>


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=5;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_CILINDRO,OBJECT_CONO, OBJECT_ESFERA, OBJECT_PLY,OBJECT_TANQUE, OBJECT_TABLERO} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();
  void pick();

public slots:
  void idle_event();
  void camera_move();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  Object_Ply Ply;
  cilindro cil;
  cono cone;
  esfera sphere;
  Tanque tank;
  chess_board tablero;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
  float Observer_distanceOrtho;

  double first_degree = 0;
  double first_degreeCre = 1;
  double second_degree = 0;
  double second_degreeCre = 1;
  double third_degree = 0.05;
  double third_degreeCre = 0.05;
  double giraRueda = 0;
  bool animacion = false;

  QTimer *reloj;
  int contador;
  int contador1;
  int contador2;

  Iluminacion luz;
  bool Goraud;
  bool Flat;
  bool firstlight;
  bool secondlight;

  int M;
  bool Mater;

  bool texture;

  bool camera;
  QTimer *reloj1;
  int alto;
  int ancho;
  QPoint globalcursorpos;
  _vertex2f cursor;

  bool vista;

};

#endif
