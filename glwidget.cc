/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

}

// Skeleton for pick fuction using glDeleteFramebuffers
//
// Domingo Martín Perandrés
// GPL
//
// Window_width and Window_height are the widht and height of the device window
// Selection_position_x and Selection_position_y are the coordinates of the mouse

//void _gl_widget::pick()
//{
//  makeCurrent();

//  int Window_width = ancho;
//  int Window_height = alto;

//  // Frame Buffer Object to do the off-screen rendering
//  GLuint FBO;
//  glGenFramebuffers(1,&FBO);
//  glBindFramebuffer(GL_FRAMEBUFFER,FBO);

//  // Texture for drawing
//  GLuint Color_texture;
//  glGenTextures(1,&Color_texture);
//  glBindTexture(GL_TEXTURE_2D,Color_texture);
//  // RGBA8
//  glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
//  // this implies that there is not mip mapping
//  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

//  // Texure for computing the depth
//  GLuint Depth_texture;
//  glGenTextures(1,&Depth_texture);
//  glBindTexture(GL_TEXTURE_2D,Depth_texture);
//  // Float
//  glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

//  // Attatchment of the textures to the FBO
//  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
//  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

//  // OpenGL will draw to these buffers (only one in this case)
//  static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
//  glDrawBuffers(1,Draw_buffers);

//  /*************************/

//  // dibujar escena para seleccion

//  /*************************/

//  // get the pixel
//  int Color;
//  glReadBuffer(GL_FRONT);
//  glPixelStorei(GL_PACK_ALIGNMENT,1);
//  glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

//  /*************************/

//  // convertir de RGB a identificador

//  // actualizar el identificador de la parte seleccionada en el objeto

//  /*************************/

//  glDeleteTextures(1,&Color_texture);
//  glDeleteTextures(1,&Depth_texture);
//  glDeleteFramebuffers(1,&FBO);
//  // the normal framebuffer takes the control of drawing
//  glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
//}

/*****************************************************************************//**
 * Evento movimiento aleatorio
 *
 *
 *
 *****************************************************************************/


void _gl_widget::idle_event(){

    if(first_degree < 90 && contador == 0){
        first_degree += 0.05;
    }
    else contador = 1;

    if(first_degree > -90 && contador == 1){
        first_degree -= 0.05;
    }
    else contador = 0;

    if(second_degree > -30 && contador1 == 0 && contador == 0){
        second_degree -= 0.05;
    }
    else contador1 = 1;

    if(second_degree < 0 && contador1 == 1 && contador == 1){
        second_degree += 0.05;
    }
    else contador1 = 0;

    if(third_degree < 0.45 && contador2 == 0 && contador == 0){
        third_degree += 0.005;
    }
    else contador2 = 1;

    if(third_degree > -0.35 && contador2 == 1 && contador == 1){
        third_degree -= 0.005;
    }
    else contador2 = 0;


    giraRueda+=0.5;

    luz.ai+=0.01;


    update();
}

void _gl_widget::camera_move(){

    globalcursorpos = QCursor::pos();
    cursor(globalcursorpos.x(),globalcursorpos.y());
    Observer_angle_x = cursor.y;
    Observer_angle_y = cursor.x;


    update();
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/


void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CILINDRO;break;
  case Qt::Key_4:Object=OBJECT_CONO;break;
  case Qt::Key_5:Object=OBJECT_ESFERA;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_TANQUE;break;
  case Qt::Key_8:Object=OBJECT_TABLERO;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;
  case Qt::Key_E: first_degreeCre += 1; break;
  case Qt::Key_R:if(first_degreeCre == 0) first_degreeCre = 1;else first_degreeCre -= 1; break;
  case Qt::Key_Q:first_degree += first_degreeCre; break;
  case Qt::Key_W:first_degree -= first_degreeCre; break;
  case Qt::Key_T:second_degreeCre += 1; break;
  case Qt::Key_Y:if(second_degreeCre == 0) second_degreeCre = 1;else second_degreeCre -= 1; break;
  case Qt::Key_S:if(second_degree >= 0) second_degree = 0;else second_degree += second_degreeCre;break;
  case Qt::Key_D:if(second_degree <= -60)  second_degree = -60;else second_degree -= second_degreeCre; break;
  case Qt::Key_U:third_degreeCre += 0.05; break;
  case Qt::Key_I:if(third_degreeCre == 0) third_degreeCre = 0.05; else third_degreeCre -= 0.05; break;
  case Qt::Key_Z:if(third_degree >= 0.5) third_degree = 0.5;else third_degree += third_degreeCre; break;
  case Qt::Key_X:if(third_degree <= -0.4) third_degree = -0.4; else third_degree -= third_degreeCre; break;
  case Qt::Key_A:{
    animacion = !animacion;
    if(animacion){
        reloj->start();
    }
    else{
        reloj->stop();
    }
  }break;

  case Qt::Key_F3:Flat = !Flat;break;
  case Qt::Key_F4:Goraud = !Goraud;break;
  case Qt::Key_F5:texture = !texture;break;
  case Qt::Key_J:{
      firstlight = !firstlight;
  }break;     
  case Qt::Key_K:{
      secondlight = !secondlight;
  }break;

  case Qt::Key_M: if(Mater) M++; if(M == 3) M = 0; else Mater = !Mater ;break;


  case Qt::Key_0:{
    camera = !camera;
    if(camera){
        reloj1->start();
    }
    else{
        reloj1->stop();
    }
  }break;


  case Qt::Key_V:vista=!vista;break;
  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:{
      if(vista)
          Observer_distanceOrtho++;
      else
          Observer_distance*=1.2;
  }break;

  case Qt::Key_PageDown:{
      if(vista)
          Observer_distanceOrtho--;
      else
          Observer_distance/=1.2;
  }break;

  }


  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if(vista){
      glPopMatrix();
      glPushMatrix();
      glOrtho(-Observer_distanceOrtho,Observer_distanceOrtho,-Observer_distanceOrtho,Observer_distanceOrtho,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  }
  else {
      glPopMatrix();
      glPushMatrix();
      glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

  }

}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);

}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if(firstlight){
      luz.infinite();
  }
  else
      luz.noinfinite();

  if(secondlight){
      luz.near();
  }
  else
      luz.nonear();

  if(secondlight ==false && firstlight == false)
      luz.noiluminacion();

    if(Flat){
        switch (Object){
        case OBJECT_TABLERO:tablero.FlatShading();break;
        case OBJECT_CILINDRO:cil.FlatShading();break;
        case OBJECT_CONO:cone.FlatShading();break;
        case OBJECT_ESFERA:sphere.FlatShading();break;
        case OBJECT_PLY:Ply.FlatShading();break;
        default:break;
        }
    }

  if(Goraud){

      switch (Object){
      case OBJECT_TABLERO:tablero.GouraudShading();break;
      case OBJECT_CILINDRO:cil.GouraudShading();break;
      case OBJECT_CONO:cone.GouraudShading();break;
      case OBJECT_ESFERA:sphere.GouraudShading();break;
      case OBJECT_PLY:Ply.GouraudShading();break;
      default:break;
      }
  }

  if(Mater){
      switch (M) {
      case 0:{
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.Material1();break;
          case OBJECT_CUBE:Cube.Material1();break;
          case OBJECT_PLY:Ply.Material1();break;
          case OBJECT_CILINDRO:cil.Material1();break;
          case OBJECT_CONO:cone.Material1();break;
          case OBJECT_ESFERA:sphere.Material1();break;
          default:break;
          }
      }break;
      case 1:{
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.Material2();break;
          case OBJECT_CUBE:Cube.Material2();break;
          case OBJECT_PLY:Ply.Material2();break;
          case OBJECT_CILINDRO:cil.Material2();break;
          case OBJECT_CONO:cone.Material2();break;
          case OBJECT_ESFERA:sphere.Material2();break;
          default:break;
          }
      }break;
      case 2:{
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.Material3();break;
          case OBJECT_CUBE:Cube.Material3();break;
          case OBJECT_PLY:Ply.Material3();break;
          case OBJECT_CILINDRO:cil.Material3();break;
          case OBJECT_CONO:cone.Material3();break;
          case OBJECT_ESFERA:sphere.Material3();break;
          default:break;
          }
      }break;
      }

  }



  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case OBJECT_CILINDRO:cil.draw_point();break;
    case OBJECT_CONO:cone.draw_point();break;
    case OBJECT_ESFERA:sphere.draw_point();break;
    case OBJECT_TANQUE:tank._draw_point(first_degree, second_degree,third_degree, giraRueda);break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case OBJECT_CILINDRO:cil.draw_line();break;
    case OBJECT_CONO:cone.draw_line();break;
    case OBJECT_ESFERA:sphere.draw_line();break;
    case OBJECT_TANQUE:tank._draw_line(first_degree, second_degree,third_degree, giraRueda);break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    case OBJECT_CILINDRO:{
        if(texture == false){
            glDisable(GL_TEXTURE_2D);
            cil.draw_fill();
        }
        else{
            tablero.load();
            tablero.drawCilindro();
        }
    }break;
    case OBJECT_CONO:cone.draw_fill();break;
    case OBJECT_ESFERA:{
        if(texture == false){
            glDisable(GL_TEXTURE_2D);
            sphere.draw_fill();
        }
        else{
            tablero.load();
            tablero.drawSphere();
        }
    }break;
    case OBJECT_TANQUE:tank._draw_fill(first_degree, second_degree,third_degree, giraRueda);break;
    case OBJECT_TABLERO:{
        if(texture == false){
            glDisable(GL_TEXTURE_2D);
            tablero.draw_tablero();
        }
        else{
            tablero.load();
            tablero.drawPanel();
        }
    }break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_CILINDRO:cil.draw_chess();break;
    case OBJECT_CONO:cone.draw_chess();break;
    case OBJECT_ESFERA:sphere.draw_chess();break;
    default:break;
    }
  }

}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
  ancho=Width1;
  alto=Height1;
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;
  Observer_distanceOrtho = 5;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;

  contador = 0;
  contador1 = 0;
  contador2 = 0;


  Goraud = false;
  Flat = false;
  firstlight = false;
  secondlight = false;

  M = 0;
  Mater = false;

  reloj = new QTimer;
  reloj->setInterval(0);
  connect(reloj, SIGNAL(timeout()), this, SLOT(idle_event()));

  reloj1 = new QTimer;
  reloj1->setInterval(0);
  connect(reloj1, SIGNAL(timeout()), this, SLOT(camera_move()));

  texture = false;
  camera=false;

  vista = false;


}
