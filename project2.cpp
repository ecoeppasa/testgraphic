#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include <SOIL/SOIL.h>

float sumbux=0.0, sumbuy=0.0, sumbuz=0.0;
float sudut=0.0f;
float vektorx=0.0f, vektorz=-1.0f;
float x=0.0f, z=5.0f;
float pindahx =0.0, pindahy=0.0, pindahz=0.0;
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, putary=0, angle=0.0; //Rotasi Sudut
float inner, outer; int garisv,garish; //Variabel Torus
GLuint depan;
GLuint belakang;
GLuint atas;
GLuint bawah;
GLuint kiri;
GLuint kanan;
GLuint batu;
GLuint rumput;

void setapak();

void bangun (int w, int h)
{
     if (h == 0)
		h = 1;
	float rasio =  w * 1.0 / h;
     
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     glViewport (0,0, w, h);
     gluPerspective(70.0f, rasio, 0.3f, 100.0f);
     glMatrixMode(GL_MODELVIEW);
     glOrtho(0.0,2.0,0.0,2.0,-2.0,2.0);
}

GLuint Tatas() // Load bitmaps dan mengkonversi texture
{
/* load file image */
atas = SOIL_load_OGL_texture("a.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return atas;
}

GLuint Tbawah() // Load bitmaps dan mengkonversi texture
{
/* load file image */
bawah = SOIL_load_OGL_texture("b.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return bawah;
}
GLuint Tdepan() // Load bitmaps dan mengkonversi texture
{
/* load file image */
depan = SOIL_load_OGL_texture("c.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return depan;
}

GLuint Tbelakang() // Load bitmaps dan mengkonversi texture
{
/* load file image */
belakang = SOIL_load_OGL_texture("pemandangan.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return belakang;

}
GLuint Tkiri() // Load bitmaps dan mengkonversi texture
{
/* load file image */
kiri = SOIL_load_OGL_texture("f.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return kiri;
}
GLuint Tkanan() // Load bitmaps dan mengkonversi texture
{
/* load file image */
kanan = SOIL_load_OGL_texture("b.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return kanan;
}
GLuint Tbatu() // Load bitmaps dan mengkonversi texture
{
/* load file image */
batu = SOIL_load_OGL_texture("texture batu.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return batu;
}
GLuint Trumput() // Load bitmaps dan mengkonversi texture
{
/* load file image */
rumput = SOIL_load_OGL_texture("rumput.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
/* pengecekan eror */

// menentukan tipe texture dari image

return rumput;
}

void init (void)
{
     Tatas();
     Tbawah();
     Tdepan();
     Tbelakang();
     Tkiri();
     Tkanan();
     Tbatu();
     Trumput();
     GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat mat_shininess[] = {50.0};
     GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.0}; 
     
     glClearColor (0.0, 0.0, 0.0, 0.0);
     glShadeModel (GL_SMOOTH);
     
     //SHADING
     glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
     
     glEnable(GL_DEPTH_TEST);
}

//Garis Koordinat
void koordinatx(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(-4,0);
     glVertex2f(-2.6,0);
     glEnd();
}

void koordinaty(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(0,3);
     glVertex2f(0,-3);
     glEnd();
}

void koordinatz(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(0,0);
     glVertex2f(5.4,3);
     glEnd();
}
// Akhir Garis Koordinat

//kerucut

void cone (float diameter, float tinggi, int garisv, int garish)
{
     glutSolidCone(diameter,tinggi,garisv,garish);
}

void wirecone (float diameter, float tinggi, int garisv, int garish)
{
     glutWireCone(diameter,tinggi,garisv,garish);
}

//BANGUN
void kubus (void)
{
     glutWireCube(0.5);
}
void kubussolid (void)
{
     glutSolidCube(0.5);
}

void bola ()
{
     glutWireSphere(0.5,10,10);
}
void bolasolid (float diameter, int garisv, int garish)
{
     glutSolidSphere(diameter,garisv,garish);
}

void torus(float inner, float outer, int garisv, int garish)
{
     glutWireTorus(inner,outer,garisv,garish);
}

void torussolid(float inner, float outer, int garisv, int garish)
{
     glutSolidTorus(inner,outer,garisv,garish);
}

void icosahedron()
{
     glutWireIcosahedron();
}

void dodecahedron()
{
     glutWireDodecahedron();
}

void dodecahedronsolid()
{
     glutSolidDodecahedron();
}

void kotak ()
{
     glBegin(GL_QUADS);
     glVertex2f(0.1,0.2);
     glVertex2f(0.2,0.2);
     glVertex2f(0.2,0.1);
     glVertex2f(0.1,0.1);
     glEnd();
}

void dasar()
{
    glPushMatrix();
glBindTexture(GL_TEXTURE_2D, rumput);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
   
   glBegin(GL_QUADS); //Kotak dasar
    // glColor3f(0.0,0.2,0.0);
    glNormal3f( 0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-4.0,-4.0);
    glTexCoord2f(0.0f, 0.0f);  glVertex2f(4.5,-4.0);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(4.5,4.0);
    glTexCoord2f(1.0f, 1.0f);glVertex2f(-4.0,4.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
glPopMatrix();
  
}


void camera (void) {
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glTranslated(-xpos,-ypos,-zpos);
}
void  tiang()
{
         //Alas Tiang 1
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.6,-0.827,1.10);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
         
         //Alas Tiang 2
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.15,-0.827,1.10);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
    
         //Alas Tiang 3
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.6,-0.827,1.5);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
         
         //Alas Tiang 4
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.15,-0.827,1.5);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
         
         //Tiang 1
         glPushMatrix();
         glColor3f(0.95,0.95,0.95);
         glTranslatef(-2.6,-0.67,1.10);
         glScalef(0.08,1.05,0.08);
         kubussolid();
         glPopMatrix();
         
         //Tiang 2
         glPushMatrix();
         glColor3f(0.95,0.95,0.95);
         glTranslatef(-2.15,-0.67,1.10);
         glScalef(0.08,1.05,0.08);
         kubussolid();
         glPopMatrix();
         
         //Tiang 3
         glPushMatrix();
         glColor3f(0.95,0.95,0.95);
         glTranslatef(-2.6,-0.67,1.5);
         glScalef(0.08,1.05,0.08);
         kubussolid();
         glPopMatrix();
         
         //Alas Tiang 4
         glPushMatrix();
         glColor3f(0.95,0.95,0.95);
         glTranslatef(-2.15,-0.67,1.5);
         glScalef(0.08,1.05,0.08);
         kubussolid();
         glPopMatrix();
         
         //Atas Tiang 1
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.6,-0.47,1.10);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
         
         //Atas Tiang 2
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.15,-0.47,1.10);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
    
         //Atas Tiang 3
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.6,-0.47,1.5);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
         
         //Atas Tiang 4
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.15,-0.47,1.5);
         glScalef(0.15,0.07,0.15);
         kubussolid();
         glPopMatrix();
}
void tanahdasar(){
      glPushMatrix();
     glTranslatef(0.0,-1.0,0.0);
     glRotatef(-90.0,1.0,0.0,0.0);
     dasar();
     glPopMatrix();
     }
     
     //--------------------------LABIRIN------------------------------------
     void labirin(){
          
   
   
     //dinding labirin atas
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.5,-0.84,-3.0);
     glScalef(10.90,1.5,0.1);
     kubussolid();
     glPopMatrix();
    
    //dinding labirin bawah
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.5,-0.84,0.15);
     glScalef(10.90,1.5,0.1);
     kubussolid();
     glPopMatrix();
      
     //dinding labirib kanan atas (pintu kanan)
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(3.2,-0.84,-2.5);
     glScalef(0.1,1.5,2.1);
     kubussolid();
     glPopMatrix();
     
     
    
    //dinding labirin kanan bawah (pintu kanan)
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(3.2,-0.84,-0.7);
     glScalef(0.1,1.5,3.5);
     kubussolid();
     glPopMatrix(); 
     
      //dinding labirib kiri atas (pintu kiri)
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.25,-0.84,-2.1);
     glScalef(0.1,1.5,3.5);
     kubussolid();
     glPopMatrix();
     
     
    
    //dinding labirin kiri bawah (pintu kiri)
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.25,-0.84,-0.33);
      glScalef(0.1,1.5,2.1);
     kubussolid();
     glPopMatrix(); 
     
     
     //labirin kiri dalam 1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.61,-0.84,-0.83);
     glScalef(2.62,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.8,-0.84,-0.35);
     glScalef(3.9,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 3
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.5,-0.84,-1.0);
     glScalef(0.1,1.5,2.5);
     kubussolid();
     glPopMatrix();
       //labirin kiri dalam 4
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.14,-0.84,-1.2);
     glScalef(2.62,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 5
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.8,-0.84,-1.45);
     glScalef(0.1,1.5,1.0);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 6
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.3,-0.84,-1.69);
     glScalef(2.0,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 7
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.8,-0.84,-2.30);
     glScalef(0.1,1.5,1.0);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 8
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.8,-0.84,-2.05);
     glScalef(3.9,1.5,0.1);
     kubussolid();
     glPopMatrix();
    
     //labirin kiri dalam 9
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.8,-0.84,-2.55);
     glScalef(0.1,1.5,1.9);
     kubussolid();
     glPopMatrix();
     //labirin kiri dalam 10
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.45,-0.84,-2.55);
     glScalef(1.4,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
          //labirin kiri dalam 11
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.15,-0.84,-0.54);
     glScalef(0.1,1.5,2.6);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 12
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.0,-0.84,-1.6);
     glScalef(2.2,1.5,0.1);
     kubussolid();
     glPopMatrix();
          //labirin kiri dalam 13
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.15,-0.84,-2.3);
     glScalef(0.1,1.5,1.05);
     kubussolid();
     glPopMatrix();
      //labirin kiri dalam 14
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.2,-0.84,-2.55);
     glScalef(1.4,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 15
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.55,-0.84,-1.3);
     glScalef(0.1,1.5,3.15);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 15a
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(0.55,-0.84,-2.81);
     glScalef(0.1,1.5,0.8);
     kubussolid();
     glPopMatrix();
     
         //labirin kiri dalam 16
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.84,-0.5);
     glScalef(2.2,1.5,0.1);
     kubussolid();
     glPopMatrix();
  
   //labirin kiri dalam 16a
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.84,-2.6);
     glScalef(2.2,1.5,0.1);
     kubussolid();
     glPopMatrix();
      //labirin kiri dalam 17
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.65,-0.84,-1.00);
     glScalef(0.1,1.5,2.00);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 17a
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.05,-0.84,-1.40);
     glScalef(0.1,1.5,1.90);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 18
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.60,-0.84,-1.9);
     glScalef(2.2,1.5,0.1);
     kubussolid();
     glPopMatrix();
      //labirin kiri dalam 19
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.15,-0.84,-0.7);
     glScalef(0.1,1.5,3.25);
     kubussolid();
     glPopMatrix();
     
     //labirin kiri dalam 19a
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.15,-0.84,-2.4);
     glScalef(0.1,1.5,2.15);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 21
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.60,-0.84,-1.45);
     glScalef(0.1,1.5,4.55);
     kubussolid();
     glPopMatrix();
     
      //labirin kiri dalam 18
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.9,-0.84,-1.57);
     glScalef(1.2,1.5,0.1);
     kubussolid();
     glPopMatrix();
     
     }
     
     //----------------------------JALAN SETAPAK-------------------------
     void jalansetapak(){
           
    
    float zjalan=3.7;
    
    for(int ij=1;ij<12;ij++){
     //kanan 
     glPushMatrix();
       glColor3f(0.6f, 0.6f, 0.65f);
     glTranslatef(0.0,-0.84,zjalan+0.1);
     glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     //kiri
     glPushMatrix();
       glColor3f(0.6f, 0.6f, 0.65f);
     glTranslatef(-0.28,-0.84,zjalan+0.1);
     glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak();
     glPopMatrix();
     zjalan = zjalan-0.3;
     }
    
    //ke manjang kiri
     float xjalan=-0.56;
     for(int ij=1;ij<11;ij++){
     
     glPushMatrix();
       glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(xjalan,-0.84,1.38);
      glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     xjalan = xjalan-0.28;
     }
    // kiri ke belakang    
     float zjalan2=1.07;
    
    for(int ij=1;ij<9;ij++){
   
     glPushMatrix();
     glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(-3.08,-0.84,zjalan2);
      glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     zjalan2 = zjalan2-0.3;
     }
     
     //pintu labirin kiri
     float xjalan2=-2.5;
     for(int ij=1;ij<3;ij++){
     //kanan 
    
     glPushMatrix();
       glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(xjalan2,-0.84,-1.04);
      glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     xjalan2 = xjalan2-0.28;
     }
     
     //manjang kanan
     //ke manjang kiri
     float xjalan3=3.66;
     for(int ij=1;ij<14;ij++){
     
     glPushMatrix();
       glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(xjalan3,-0.84,1.38);
      glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     xjalan3 = xjalan3-0.28;
     }
     
     // kanan ke belakang    
     float zjalan4=1.07;
    
    for(int ij=1;ij<12;ij++){
   
     glPushMatrix();
     glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(3.65,-0.84,zjalan4);
      glScalef(0.12,0.01,0.12);
     //kubussolid();
     setapak ();
     glPopMatrix();
     zjalan4 = zjalan4-0.3;
     }
     
          }
          //-----------------------------LAMPU TAMAN------------------
          
void lamputaman()
{
     glPushMatrix();
     glTranslatef(2.85,-0.5,0.5);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
          
     glPushMatrix();
     glTranslatef(2.85,-0.77,0.5);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();               
}
          
          //----------------------POHON----------------------------
     void pohon(){
          //------------------pohon pinggir------------------------
      float zpohon,xpohon;
    // kiri
      for (zpohon=-3.50;zpohon<4.0;zpohon++){
      //tangkal
     glPushMatrix();
     glTranslatef(-3.80,-0.78,zpohon);
     glScalef(0.09,1.4,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
     //pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-3.80,-0.78,zpohon);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-3.80,-0.78,zpohon);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-3.80,-0.78,zpohon);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     zpohon=zpohon+0.01;
     }
     //belakang
      for (xpohon=-2.8;xpohon<4.0;xpohon++){
      //tangkal
     glPushMatrix();
     glTranslatef(xpohon,-0.78,-3.50);
     glScalef(0.09,1.4,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
     //pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(xpohon,-0.78,-3.50);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(xpohon,-0.78,-3.50);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(xpohon,-0.78,-3.50);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     xpohon=xpohon+0.01;
     }
     
     //kanan
     
      
      for (zpohon=-3.50;zpohon<4.0;zpohon++){
      //tangkal
     glPushMatrix();
     glTranslatef(4.30,-0.78,zpohon);
     glScalef(0.09,1.4,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
     //pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(4.30,-0.78,zpohon);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(4.30,-0.78,zpohon);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(4.30,-0.78,zpohon);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     zpohon=zpohon+0.01;
     }
     
     //------------------akhir pohon pinggir------------------
     
     //tangkal
     glPushMatrix();
     glTranslatef(-2.55,-0.78,2.1);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
     //pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.85,2.1);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.75,2.1);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.65,2.1);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
    
    //pohon kanan depan
     
     //tangkal
    glPushMatrix();
    glTranslatef(0.3,0.0,0.0);
     glPushMatrix();
     glTranslatef(1.1,-0.78,2.1);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.85,2.1);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.75,2.1);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.65,2.1);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
   glPopMatrix();
    //pohon kanan belakang
    
    //tangkal
    glPushMatrix();
    glTranslatef(0.3,0.0,0.0);
     glPushMatrix();
     glTranslatef(1.1,-0.78,0.57);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.85,0.57);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.75,0.57);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.65,0.57);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix(); 
    glPopMatrix();
     
     
     //pemantau
     glPushMatrix();
     glTranslatef(3.2,0.0,-0.6);
          //Alas
         glPushMatrix();
         glColor3f(0.9,0.8, 0.7);
         glTranslatef(-2.4,-0.92,1.3);
         glScalef(1.2,0.3,1.2);
         kubussolid();
         glPopMatrix();
         
         //tiang bawah
         glPushMatrix();
         tiang();
         glPopMatrix();
         
         //tiang atas
         glPushMatrix();
         glTranslatef(0.0,0.495,0.0);
         tiang();
         glPopMatrix();
         
         
         //Atap
         glPushMatrix();
         glColor3f(0.3,0.2,0.0);
         glTranslatef(-2.37,0.08,1.3);
         glScalef(0.03,0.30,0.03);
         glRotatef(-90.0,1.0,0.0,0.0);
         cone (13.0,0.9,50,8);
         glPopMatrix();
         
         //lantai2
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.38,-0.4,1.3);
         glScalef(1.5,0.2,1.5);
         kubussolid();
         glPopMatrix();
         
         //Tangga 1
         glPushMatrix();
         glColor3f(0.8,0.8,0.8);
         glTranslatef(-2.73,-0.945,1.3);
         glScalef(0.1,0.2,0.5);
         kubussolid();
         glPopMatrix();
         
         //Tangga 2
         glPushMatrix();
         glColor3f(0.7,0.7,0.7);
         glTranslatef(-2.78,-0.962,1.3);
         glScalef(0.1,0.15,0.5);
         kubussolid();
         glPopMatrix();
         
         //Tangga 3
         glPushMatrix();
         glColor3f(0.6,0.6,0.6);
         glTranslatef(-2.83,-0.974,1.3);
         glScalef(0.1,0.1,0.5);
         kubussolid();
         glPopMatrix();
         
         //Tangga 4
         glPushMatrix();
         glColor3f(0.5,0.5,0.5);
         glTranslatef(-2.88,-0.987,1.3);
         glScalef(0.1,0.05,0.5);
         kubussolid();
         glPopMatrix();
         glPopMatrix();
}
    
void setapak(){
glPushMatrix();
glBindTexture(GL_TEXTURE_2D, batu);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
   
     glBegin(GL_QUADS);
// atas
glNormal3f( 0.0f, 1.0f, 0.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//--------------------------------------------------------------------------------------
               glPushMatrix();
      
     glBegin(GL_QUADS);
    // depan
glNormal3f( 0.0f, 0.0f, 1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);


// belakang
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);


// bawah
glNormal3f( 0.0f,-1.0f, 0.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);


// kanan
glNormal3f( 1.0f, 0.0f, 0.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);

// kiri
glNormal3f(-1.0f, 0.0f, 0.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glEnd();
glPopMatrix();          
               
               }
          
          void pemandangan(){
               glPushMatrix();
glBindTexture(GL_TEXTURE_2D, depan);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0);    
     glBegin(GL_QUADS);
// depan
glNormal3f( 0.0f, 0.0f, 1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

glEnd();
glPopMatrix();
//---------------------------------------------------------------------------------
glPushMatrix();
glBindTexture(GL_TEXTURE_2D, belakang);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0); 
 
     glBegin(GL_QUADS);
// belakang
glNormal3f( 0.0f, 0.0f,-1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
glEnd();
glPopMatrix();

//------------------------------------------------------------------------------------
               glPushMatrix();
glBindTexture(GL_TEXTURE_2D, atas);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0);    
     glBegin(GL_QUADS);
// atas
glNormal3f( 0.0f, 1.0f, 0.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glEnd();
glPopMatrix();
//--------------------------------------------------------------------------------------
               glPushMatrix();
glBindTexture(GL_TEXTURE_2D, bawah);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0);    
     glBegin(GL_QUADS);
// bawah
glNormal3f( 0.0f,-1.0f, 0.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
glEnd();
glPopMatrix();
//--------------------------------------------------------------------------------------
               glPushMatrix();
glBindTexture(GL_TEXTURE_2D, kanan);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0);    
     glBegin(GL_QUADS);
// kanan
glNormal3f( 1.0f, 0.0f, 0.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
glEnd();
glPopMatrix();
//--------------------------------------------------------------------------------------
               glPushMatrix();
glBindTexture(GL_TEXTURE_2D, kiri);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glEnable(GL_TEXTURE_2D);
glScalef(50,50,50);
glColor3f(1.0,1.0,1.0);    
     glBegin(GL_QUADS);
// kiri
glNormal3f(-1.0f, 0.0f, 0.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
glEnd();
glPopMatrix();
               }
               
               
               
void bouncyCastle() {
       
    //sisi kanan
    glColor3f(1, 0.58, 0);
    glPushMatrix();
    glScaled(5.80, 1.0, 5.80);
    glTranslatef(1, 0.5, 0);
    glutSolidCube(2);
    glPopMatrix();
    glPushMatrix();
    
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 2.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 4.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //sisi belakang
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 0.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 1.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 2.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 3.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 4.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-6.0f, 5.0f, 6.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //sisi kiri
    glPushMatrix();
    glTranslatef(12.0f, 0.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12.0f, 1.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12.0f, 2.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12.0f, 3.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12.0f, 4.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(12.0f, 5.0f, 0.0f);
    glScaled(1.0, 1.0, 15.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //tiang 1
    //glColor3f(0.8, 0.2, 0.3);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(12.0f, 6.0f, -3.5f);
    glScaled(1.4, 1.4, 11.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //tiang 2
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.0f, 6.0f, -3.5f);
    glScaled(1.4, 1.4, 11.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //tiang 3
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.0f, -6.0f, -3.5f);
    glScaled(1.4, 1.4, 11.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //tiang 4
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(12.0f, -6.0f, -3.5f);
    glScaled(1.4, 1.4, 11.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //tangga
    glColor3f(0.2, 0.3, 1);
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(6.0f, 0.6f, 6.0f);
    glScaled(1.0, 1.0, 13.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(7.0f, 0.3f, 6.0f);
    glScaled(1.0, 1.0, 13.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(8.0f, 0.0f, 6.0f);
    glScaled(1.0, 1.0, 13.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //gate
    glColor3f(0.8, 0.2, 0.3);
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(15, 1.0, 0.0, 0.0);
    glTranslatef(6.0f, 10.0f, 6.0f);
    glScaled(1.0, 1.0, 8.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(-15, 1.0, 0.0, 0.0);
    glTranslatef(6.0f, 7.0f, 5.0f);
    glScaled(1.0, 1.0, 8.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(6.0f, 5.8f, -9.0f);
    glScaled(1.2, 1.2, 5.0);
    glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();

    //kerucut
    glColor3f(0.55, 0.34, 0.114);
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(5.8f, 6.0f, 10.8f);
    glutSolidCone(0.7, 1.5, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(12.0f, 6.0f, 7.8f);
    glutSolidCone(0.7, 1.5, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(12.0f, -6.0f, 7.8f);
    glutSolidCone(0.7, 1.5, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, 6.0f, 7.8f);
    glutSolidCone(0.7, 1.5, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, -6.0f, 7.8f);
    glutSolidCone(0.7, 1.5, 10, 10);
    glPopMatrix();
}


void monkeyLadder() {
    //tiang kiri kanan depan
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(-5, 0, 35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(5, 0, 35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    //tiang kiri kanan belakang
    glPushMatrix();

    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(-5, 0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(5, 0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    //tiang atas
    glPushMatrix();
    glTranslatef(0.0, 19.0, 0.0);
    glScalef(1.0, 1.0, 1.7);
    glRotatef(90, 1.0, 0.0, 0.0);


    glPushMatrix();

    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(-5.0, 0.0, 0.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 20.0, 1.0);
    glTranslatef(5.0, 0.0, 0.0);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();





    //tiang tangga depan
    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -15.0, 35.0);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -5.0, 35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 5.0, 35.0);
    glutSolidCube(2);
    glPopMatrix();

    //tiang tangga belakang
    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -15.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -5.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 5.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();


    //tiang tangga atas depan
    glPushMatrix();
    glTranslatef(0.0, -16.0, 16.0);
    glRotatef(90, 1.0, 0.0, 0.0);


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -10.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 10.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();
    //tiang tangga atas depan
    glPushMatrix();
    glTranslatef(0.0, -16.0, -16.0);
    glRotatef(90, 1.0, 0.0, 0.0);


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, -10.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glScalef(5.0, 1.0, 1.0);
    glTranslatef(0.0, 10.0, -35.0);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
}

void kursi(void)
{
     glPushMatrix();
     glScalef(3.0,3.9,1.0);
         glPushMatrix();
         glColor3f(0.8f, 0.5f, 0.3f);
         glTranslatef(1.0,-0.987,2.7);
         glScalef(0.35,0.03,0.40);
         kubussolid();
         glPopMatrix(); 
         
         glPushMatrix();
         glColor3f(0.85f, 0.5f, 0.3f);
         glTranslatef(1.0,-0.972,2.704);
         glScalef(0.32,0.05,0.05);
         kubussolid();
         glPopMatrix();
     glPopMatrix();
}
               
               // ##################################DISPLAY####################################
void display (void)
{
     const double waktu = glutGet (GLUT_ELAPSED_TIME) / 1000.0;
     const double lama1 = 50*waktu, lama2 = 10*waktu, lama3 = waktu/10, lama4=10*waktu;
     GLdouble eqn[4] = {0.0, 0.0, 1.0, 0.0};
     GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};  
     GLdouble eqn3[4] = {0.0, 1.0, 0.0, 0.0};   
     GLfloat mat_transparent[] = { 0.1, 0.8, 0.8, 0.6 };
     GLfloat mat_emission[] = { 0.0, 0.3, 0.3, 0.6 };
     GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
     GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
     //GLfloat light_position[] = {0.0, 0.0, 1.0, 1.0};
          
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(0.7,0.7,1.0,0.5);
     
     glLoadIdentity();
     
     //Setting Kamera
     gluLookAt(x, 0.0, z, x+vektorx, 0.0, z+vektorz, 0.0, 1.0, 0.0);
     camera();
     glEnable(GL_TEXTURE_2D);
     glEnable(GL_COLOR_MATERIAL);
     //glColorMaterial(GL_FRONT,GL_SPECULAR);
     glPushMatrix();
      //CLIP untuk Y < 0
     glClipPlane(GL_CLIP_PLANE0,eqn);
     glEnable(GL_CLIP_PLANE0);
     
     //CLIP untuk X < 0
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glPopMatrix();
     glDisable(GL_CLIP_PLANE0);
     glDisable(GL_CLIP_PLANE1);
    
    
    
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
     tanahdasar();
     labirin();
     jalansetapak();
     pohon();
     glPopMatrix();
     //kursi
     glPushMatrix();
     glTranslatef(0.0,0.0,0.0);
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.0);
             kursi();
         glPopMatrix();
         
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.50);
             kursi();
         glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(1.0,0.0,0.0);
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.0);
             kursi();
         glPopMatrix();
         
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.50);
             kursi();
         glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(-1.0,0.0,0.0);
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.0);
             kursi();
         glPopMatrix();
         
         glPushMatrix();     
             glTranslatef(-5.0,3.0,0.50);
             kursi();
         glPopMatrix();
     glPopMatrix();
     //akhir kursi
     
   
     
     //lampu taman
     
     
     glPushMatrix();
     glTranslatef(-5.0,0.0,0.0);
     lamputaman();
     glPopMatrix();
     //akhir lampu taman
     
     glPushMatrix();
     pemandangan();
     glPopMatrix();
     
      glPushMatrix();
     glRotatef(180,0.0,1.0,0.0);
     glTranslatef(-2.4,-0.92,-2.5);
     glScalef(0.05,0.06,0.05);
     bouncyCastle();
     glPopMatrix();
      
     glPushMatrix();
     glTranslatef(3.4,-0.8,1.9);
     glScalef(0.01,0.01,0.01);
     monkeyLadder();
     glPopMatrix();
     
     glFlush();
     glutSwapBuffers();
     angle++;
     




}

//FUNGSI KEYBOARD
void keyboard (unsigned char key, int x, int y)
{
     switch (key){
            case 'w':
            case 'W':
                 xrot += 1;
              if (xrot >90) 
              xrot -= 90;
            break;
            case 's':
            case 'S':
                  xrot -= 1;
              if (xrot < -5) 
              xrot += 5;
            break;
            case 'a':
            case 'A':
                 yrot += 1;
              if (yrot >360) 
              yrot -= 360;
            break;
            case 'd':
            case 'D':
                 yrot -= 1;
              if (yrot < -360)
              yrot += 360;
            //case 'q':
            //case 'Q':
            break;
            case 'f':
            case 'F':
                 putary -= 90;
              if (putary < -360)
              putary += 360;
            break;
            case 'h':
            case 'H':
                 putary += 90;
              if (putary >360) 
              putary -= 360;
            break;
            case 27:
                  //glutLeaveGameMode();
                 exit (0);
                }
     
}

void mouse(int klik, int state, int xx, int yy)
{
     
     switch(klik){
                  case GLUT_LEFT_BUTTON:
                       
                       if((putary==-270)||(putary==90))
                       {
                       pindahx  +=0.1f;
                       }
                       if((putary==180)||(putary==-180))
                       {
                       pindahy  -=0.1f;
                       }
                       if((putary==-90)||(putary==270))
                       {
                       pindahx  -=0.1f;
                       }
                       if((putary==0) || (putary==360) || (putary==-360))
                       {
                       pindahy  +=0.1f;
                       }
                  }
    switch(klik){
                  case GLUT_RIGHT_BUTTON:
                       
                       if((putary==-270)||(putary==90))
                       {
                       pindahx  -=0.1f;
                       }
                       if((putary==180)||(putary==-180))
                       {
                       pindahy  +=0.1f;
                       }
                       if((putary==-90)||(putary==270))
                       {
                       pindahx  +=0.1f;
                       }
                       if((putary==0) || (putary==360) || (putary==-360))
                       {
                       pindahy  -=0.1f;
                       }
                  }            
}

void ketik(int key, int xx, int yy)
{
     int mod;
     float fraksi = 0.1f;
          switch(key){
         case GLUT_KEY_F1:
              mod = glutGetModifiers();
              if(mod == (GLUT_ACTIVE_ALT)){
                     sumbux=1.0;
                     sumbuy=0.0;
                     sumbuz=0.0;
                     }
              break;
         case GLUT_KEY_F2:
              sumbux=0.0;
              sumbuy=1.0;
              sumbuz=0.0;
              break;
         case GLUT_KEY_F3:
              sumbux=0.0;
              sumbuy=0.0;
              sumbuz=1.0;
              break;
         case GLUT_KEY_LEFT:
              sudut -=0.01f;
              vektorx = sin(sudut);
              vektorz = -cos(sudut);
              break;
         case GLUT_KEY_RIGHT:
              sudut += 0.01f;
			  vektorx = sin(sudut);
			  vektorz = -cos(sudut);
			break;
         case GLUT_KEY_UP:
              x += vektorx * fraksi;
			  z += vektorz * fraksi;
			break;
         case GLUT_KEY_DOWN:
              x -= vektorx * fraksi;
			  z -= vektorz * fraksi;
         break; 
         case GLUT_KEY_PAGE_UP:
              xrot += 1;
              if (xrot >360) 
              xrot -= 360;
         break;
         case GLUT_KEY_PAGE_DOWN:
              xrot -= 1;
              if (xrot < -360) 
              xrot += 170;
         break;
         case GLUT_KEY_HOME:
              yrot -= 1;
              if (yrot < -360)
              yrot += 360;
         break;
         case GLUT_KEY_END:
              yrot += 1;
              if (yrot >360) 
              yrot -= 360;
         }
              
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutGameModeString( "1024×768:32@75" ); //the settings for fullscreen mode
    //glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
    glutInitWindowSize(1010,690);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Program Tugas Besar Konputer Grafika");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(bangun);
//    glutTimerFunc(33, TimerFunction, 1);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(ketik);
    glutMouseFunc(mouse);
    
    glEnable(GL_DEPTH_TEST);
    
    glutMainLoop();
    return 0;
}
