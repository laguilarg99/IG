#include "chess_board.h"

chess_board::chess_board()
{
}

void chess_board::translate() const{
    glPushMatrix();
    glTranslatef(0,0,-0.0051);
    glColor3f(1,1,1);

}

void chess_board::load(){

    // Code for reading an image
    if (image.load("../texturas/dia_8192.jpg")==false) cout << "Image not loaded" << endl;


       image=image.mirrored();
       image=image.convertToFormat(QImage::Format_RGB888);

       // Code to control the application of the texture
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


       //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

       // Code to pass the image to OpenGL to form a texture 2D
       glTexImage2D(GL_TEXTURE_2D,0,3,image.width(),image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,image.bits());

}


void chess_board::draw_tablero(){
    translate();
    pantalla.draw_fill();
    glPopMatrix();
}

void chess_board::drawPanel(){

    translate();
    pantalla.draw_fill();
    glPopMatrix();


    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(-3, 2 , 0.0); //
        glTexCoord2f(1.0, 1.0);
        glVertex3f(3, 2, 0.0); //
        glTexCoord2f(1.0, 0.0);
        glVertex3f(3, -2, 0.0); //
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-3, -2, 0.0); //
    glEnd();


}

void chess_board::drawCilindro(){

    glPushMatrix();
    glScalef(0.9949,0,0.9949);
    glColor3f(1,1,1);
    cil.draw_fill();
    glPopMatrix();


    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUAD_STRIP);



    for(double i = 0; i <= 2*M_PI; i += 0.01){
        const double tc = (i/(2*M_PI));
        glTexCoord2f(tc, 0.0);
        glVertex3f(cos(i),-1,sin(i));
        glTexCoord2f(tc,1.0);
        glVertex3f(cos(i),1,sin(i));

    }

    glTexCoord2f( 0.0, 0.0 );
    glVertex3f(1,0, 0);
    glTexCoord2f( 0.0, 1.0 );
    glVertex3f(1, 1, 0);


    glEnd();

}

void chess_board::drawSphere(){

    glPushMatrix();
    glScalef(0.993,0.993,0.993);
    glColor3f(1,1,1);
    sphere.draw_fill();
    glPopMatrix();

    double x,y,z;

    glEnable(GL_TEXTURE_2D);

    for(double i =0; i <=180; i+=180/30)
       {

           glBegin( GL_QUAD_STRIP ) ;
           for(double j =0 ; j <=360 ; j+=360/30)
           {

               double angle1 = j*M_PI/180;
               double angle2 = i*M_PI/180;

               //Vertex 1
               x = cos(angle1) * sin(angle2) ;
               y = sin(angle1) * sin(angle2) ;
               z = cos(angle2) ;
               glTexCoord2d(j/360, i/180);
               glVertex3d( x, y, z ) ;


               //Vetex 2
               x = cos(angle1) * sin( (i + 180/30)* M_PI/180) ;
               y = sin(angle1) * sin((i + 180/30) * M_PI/180) ;
               z = cos( (i + 180/30) * M_PI/180 ) ;
               glTexCoord2d(j/360, (i + 180/30)/(180));
               glVertex3d( x, y, z );


               //Vertex 3
               x = cos((j + 360/30) * M_PI/180) * sin((i) * M_PI/180) ;
               y = sin((j + 360/30) * M_PI/180) * sin((i) * M_PI/180) ;
               z = cos((i) * M_PI/180 ) ;
              glTexCoord2d((j + 360/30)/360 ,(i)/180);
                glVertex3d( x, y, z ) ;


               //Vertex 4
               x = cos((j + 360/30) * M_PI/180) * sin((i + 180/30)* M_PI/180) ;
               y = sin((j + 360/30)* M_PI/180) * sin((i + 180/30)* M_PI/180) ;
               z = cos((i + 180/30)* M_PI/180 ) ;
               glTexCoord2d((j + 360/30)/360, (i + 180/30)/(180));
               glVertex3d( x, y, z ) ;


           }
           glEnd() ;

    }
}

