HEADERS += \
  EjeTanque.h \
  Tanque.h \
  Wheel.h \
  basetank.h \
  bocacanion.h \
  canion.h \
  chasis.h \
  chess_board.h \
  cilindro.h \
  colors.h \
  basic_object3d.h \
  cono.h \
  cube.h \
  cuerpo.h \
  cuerpocanion.h \
  esfera.h \
  file_ply_stl.h \
  headtank.h \
  iluminacion.h \
  object3d.h \
  axis.h \
  object_ply.h \
  panel.h \
  semiesfera.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  EjeTanque.cc \
  Tanque.cc \
  Wheel.cc \
  basetank.cc \
  basic_object3d.cc \
  bocacanion.cc \
  canion.cc \
  chasis.cpp \
  chess_board.cc \
  cilindro.cc \
  cono.cc \
  cube.cc \
  cuerpo.cc \
  cuerpocanion.cc \
  esfera.cc \
  file_ply_stl.cc \
  headtank.cc \
  iluminacion.cc \
  object3d.cc \
  axis.cc \
  object_ply.cc \
  panel.cc \
  semiesfera.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/lib/x86_64-linux-gnu -lGL


CONFIG += c++11
QT += widgets

DISTFILES +=
