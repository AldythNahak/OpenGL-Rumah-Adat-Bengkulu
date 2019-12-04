#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "imageloader.h"

void gambar(void);
void rumahadatbangkabelitung(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;
GLuint _textureIdkayu;
GLuint _textureIdatap;
GLuint _textureIdtikar;
GLuint _textureIdrumput;
GLuint _textureIdplat;
GLuint _textureIdk;
GLuint _textureIdtiang;
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

//void gambar(void)
//{
//    glEnable(GL_DEPTH_TEST);
//    is_depth = 1;
//	glEnable(GL_COLOR_MATERIAL);
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GL_NORMALIZE);
//    glEnable(GL_LINE_SMOOTH);
//	glShadeModel(GL_SMOOTH);
//
//	Image* image = loadBMP("kayu.bmp");
//	_textureIdkayu = loadTexture(image);
//		Image* image2 = loadBMP("atap.bmp");
//	_textureIdatap = loadTexture(image2);
//			Image* image3 = loadBMP("tikar.bmp");
//	_textureIdtikar = loadTexture(image3);
//			Image* image4 = loadBMP("rumput.bmp");
//	_textureIdrumput = loadTexture(image4);
//				Image* image5 = loadBMP("plat.bmp");
//	_textureIdplat= loadTexture(image5);
//				Image* image6 = loadBMP("k.bmp");
//	_textureIdk= loadTexture(image6);
//				Image* image7 = loadBMP("tiang.bmp");
//	_textureIdtiang= loadTexture(image7);
//delete image;
//delete image2;
//delete image3;
//delete image4;
//delete image5;
//delete image6;
//delete image7;
//}

void rumahutama(float x, float y, float z, float panjang, float tinggi, float lebar) {//texture
	//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);//jendela kiri
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x +5, y + tinggi, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + 5, y, z);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(x+12.5, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+12.5, y + tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x +20.0, y + tinggi, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x + 20.0, y, z);
                        glTexCoord2f(0.0f, 0.0f);//bawah jendela
            glVertex3f(x+5, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+5, y +10, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x +27.5, y + 10, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x +27.5, y, z);
                             glTexCoord2f(0.0f, 0.0f);//atas jendela
            glVertex3f(x+5, y+tinggi-10, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+5, y +tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x +panjang-5, y +tinggi, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x +panjang-5, y+tinggi-10, z);
    glTexCoord2f(0.0f, 0.0f);//jendela kiri 2
    glVertex3f(x+27.5, y, z);
    glTexCoord2f(1.0f, 0.0f);
     glVertex3f(x+27.5, y + tinggi, z);
   glTexCoord2f(1.0f, 1.0f);
glVertex3f(x +35, y + tinggi, z);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(x + 35, y, z);
            glTexCoord2f(0.0f, 0.0f);//jendela kanan 2
            glVertex3f(x+panjang-5, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang-5, y + tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x +panjang, y + tinggi, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x + panjang,y, z);
                            glTexCoord2f(0.0f, 0.0f);//bawah jendela
            glVertex3f(x+panjang-35, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang-35, y +10, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x +panjang-5, y + 10, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x +panjang-5, y, z);
glTexCoord2f(0.0f, 0.0f);//jendela kanan 1
 glVertex3f(x+panjang-20, y, z);
glTexCoord2f(1.0f, 0.0f);
 glVertex3f(x+panjang-20, y + tinggi, z);
  glTexCoord2f(1.0f, 1.0f);
 glVertex3f(x +panjang-12.5, y + tinggi, z);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(x + panjang-12.5,y, z);
        glTexCoord2f(0.0f, 0.0f);//
        glVertex3f(x+panjang-35, y, z);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x+panjang-35, y + tinggi, z);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x +panjang-27.5, y + tinggi, z);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x + panjang-27.5,y, z);

	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + 35, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + 35, y, z - lebar);
        	glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x+panjang-35, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang-35, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x +panjang, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x +panjang, y, z - lebar);
            glTexCoord2f(0.0f, 0.0f);//atas
        glVertex3f(x+panjang-35, y+tinggi-10, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang-35, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x +35, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x +35, y+tinggi-10, z - lebar);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);//jendela 1
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - 5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - 5);
            		glTexCoord2f(0.0f, 0.0f);//jendela 3
	glVertex3f(x, y, z-lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z-lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - lebar + 5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar + 5);
	           		glTexCoord2f(0.0f, 0.0f);//2
	glVertex3f(x, y, z-lebar+12.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z-lebar+12.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - lebar + 25.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar + 25.5);
		glTexCoord2f(0.0f, 0.0f);//
	glVertex3f(x, y, z-25.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z-25.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - 12.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - 12.5);
            glTexCoord2f(0.0f, 0.0f);// bawah
	glVertex3f(x, y, z-5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + 10, z-5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + 10, z -lebar+5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z -lebar+ 5);
            glTexCoord2f(0.0f, 0.0f);// atas
	glVertex3f(x, y+tinggi-10, z-5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y+tinggi, z-5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y+tinggi, z -lebar+5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y+tinggi-10, z -lebar+ 5);

	//Kanan
		glTexCoord2f(0.0f, 0.0f);//jendela 1
	glVertex3f(x+panjang, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y + tinggi, z - 5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y, z - 5);
            		glTexCoord2f(0.0f, 0.0f);//jendela 3
	glVertex3f(x+panjang, y, z-lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi, z-lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y + tinggi, z - lebar + 5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y, z - lebar + 5);
	           		glTexCoord2f(0.0f, 0.0f);//2
	glVertex3f(x+panjang, y, z-lebar+12.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi, z-lebar+12.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y + tinggi, z - lebar + 25.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y, z - lebar + 25.5);
            glTexCoord2f(0.0f, 0.0f);//
	glVertex3f(x+panjang, y, z-25.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + tinggi, z-25.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y + tinggi, z - 12.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y, z - 12.5);
            glTexCoord2f(0.0f, 0.0f);// bawah
	glVertex3f(x+panjang, y, z-5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y + 10, z-5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y + 10, z -lebar+5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y, z -lebar+ 5);
            glTexCoord2f(0.0f, 0.0f);// atas
	glVertex3f(x+panjang, y+tinggi-10, z-5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang, y+tinggi, z-5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang, y+tinggi, z -lebar+5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+panjang, y+tinggi-10, z -lebar+ 5);

	//Alas
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
		//Atap
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-4, y+tinggi, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang+4, y+tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang+4, y+tinggi, z - lebar-4);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x-4, y+tinggi, z - lebar-4);
            glTexCoord2f(0.0f, 0.0f);//atap teras
            glVertex3f(x-4, y+tinggi, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x + panjang+4, y+tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x + panjang+4, y+tinggi-12, z + 17);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x-4, y+tinggi-12, z + 17);
	glEnd();
}

void rumahbelakang(float x, float y, float z, float panjang, float tinggi, float lebar) {
//Depan
	glBegin(GL_QUADS);
                             glTexCoord2f(0.0f, 0.0f);//atas
            glVertex3f(-15, y+tinggi-10, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-15, y +tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(15, y +tinggi, z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(15, y+tinggi-10, z);
    glTexCoord2f(0.0f, 0.0f);//kiri
    glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 0.0f);
     glVertex3f(x, y + tinggi, z);
   glTexCoord2f(1.0f, 1.0f);
glVertex3f(x +35, y + tinggi, z);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(x + 35, y, z);
            glTexCoord2f(0.0f, 0.0f);//kanan
    glVertex3f(x+panjang-35, y, z);
    glTexCoord2f(1.0f, 0.0f);
     glVertex3f(x+panjang-35, y + tinggi, z);
   glTexCoord2f(1.0f, 1.0f);
glVertex3f(x+panjang, y + tinggi, z);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(x + panjang, y, z);
/////////////////belakang/////////////////////////
glTexCoord2f(0.0f, 0.0f);
            glVertex3f(x, y, z-lebar);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x, y +tinggi, z-lebar);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y +tinggi, z-lebar);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y, z-lebar);
        //////////////kiri//////////////////
   glTexCoord2f(0.0f, 0.0f);//jendela kiri 1
            glVertex3f(x, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x, y +tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x, y +tinggi, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y, z-2.5);
               glTexCoord2f(0.0f, 0.0f);//jendela kiri 2
            glVertex3f(x, y, z-lebar);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x, y +tinggi, z-lebar);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x, y +tinggi, z-lebar+2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y, z-lebar+2.5);
                          glTexCoord2f(0.0f, 0.0f);//tengah
            glVertex3f(x, y, z-lebar+10);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x, y +tinggi, z-lebar+10);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x, y +tinggi, z-10);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y, z-10);
                                      glTexCoord2f(0.0f, 0.0f);//bawah
            glVertex3f(x, y, z-lebar+2.5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x, y +10, z-lebar+2.5);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x, y +10, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y, z-2.5);
                    glTexCoord2f(0.0f, 0.0f);//atas
            glVertex3f(x, y+tinggi-10, z-lebar+2.5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x,  y+tinggi, z-lebar+2.5);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x, y+tinggi, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x, y+tinggi-10, z-2.5);
                //////////////kanan//////////////////
   glTexCoord2f(0.0f, 0.0f);//jendela kanan 1
            glVertex3f(x+panjang, y, z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang, y +tinggi, z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y +tinggi, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y, z-2.5);
               glTexCoord2f(0.0f, 0.0f);//jendela kanan 2
            glVertex3f(x+panjang, y, z-lebar);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang, y +tinggi, z-lebar);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y +tinggi, z-lebar+2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y, z-lebar+2.5);
                          glTexCoord2f(0.0f, 0.0f);//tengah
            glVertex3f(x+panjang, y, z-lebar+10);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang, y +tinggi, z-lebar+10);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y +tinggi, z-10);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y, z-10);
                                      glTexCoord2f(0.0f, 0.0f);//bawah
            glVertex3f(x+panjang, y, z-lebar+2.5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang, y +10, z-lebar+2.5);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y +10, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y, z-2.5);
                    glTexCoord2f(0.0f, 0.0f);//atas
            glVertex3f(x+panjang, y+tinggi-10, z-lebar+2.5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(x+panjang,  y+tinggi, z-lebar+2.5);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x+panjang, y+tinggi, z-2.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(x+panjang, y+tinggi-10, z-2.5);

            ///////////////////Alas/////////////////////
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
		////////////////Atap//////////////////
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y+tinggi, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y+tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y+tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y+tinggi, z - lebar);
glEnd();
}

void balok(float x, float y, float z, float panjang, float tinggi, float lebar) {//texture
	//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z);
	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	//Alas
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
		//Atap
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y+tinggi, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y+tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y+tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y+tinggi, z - lebar);
	glEnd();
	}

void tiang(float x, float y, float z, float panjang, float tinggi, float lebar){
//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z+0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+0.5, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-0.5, y + tinggi, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z+0.5);
	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar-0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+0.5, y + tinggi, z - lebar);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-0.5, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar-0.5);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z+0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+0.5, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+0.5, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar-0.5);
	//Kanan
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + panjang, y, z+0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang-0.5, y + tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-0.5, y + tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar-0.5);
	//Alas
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z+0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang, y, z+0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar-0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar-0.5);
		//Atap
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x+0.5, y+tinggi, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang-0.5, y+tinggi, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-0.5, y+tinggi, z - lebar);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+0.5, y+tinggi, z - lebar);
	glEnd();
}

void atap(float x, float y, float z, float panjang, float tinggi, float lebar,float letak){
//Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang/4, y + tinggi, z-lebar/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-(panjang/4), y + tinggi, z-lebar/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z);
	//Belakang
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z - lebar);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang/4, y + tinggi, z - lebar/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-(panjang/4), y + tinggi, z - lebar/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
		//Kiri
		glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+panjang/4, y + tinggi, z-lebar/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+panjang/4, y + tinggi, z - lebar/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z - lebar);
	//Kanan
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + panjang, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + panjang-(panjang/4), y + tinggi, z-lebar/2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang-(panjang/4), y + tinggi, z - lebar/2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z - lebar);
	glEnd();

	if  (letak >0){
        y = 28.1;
        //Depan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z+18);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + 17, z-4);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + panjang, y +17 , z-4);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + panjang, y, z+18);
                        glTexCoord2f(0.0f, 0.0f);
                glVertex3f(x+30, y-15, z+40);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(x+30, y , z+18);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(x + panjang-30, y  , z+18);
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(x + panjang-30, y-15, z+40);
  glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x+25, 40.0, z-lebar);
glTexCoord2f(1.0f, 0.0f);
       glVertex3f(x+25, 40.0 , z-lebar-20);
      glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + panjang-25, 40.0  , z-lebar-20);
   glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + panjang-25, 40.0, z-lebar);
	glEnd();
	}
}

void jendela(float x, float y, float z, float tinggi, float lebar,float letak){
    float jarak,n1,n2,z1,z2;
    if (letak >0)
    jarak= 3.25, n1=0.3,n2=0.7,z1=0.5,z2=-0.5;
    else
    jarak= -3.25, n1=-0.3,n2=-0.7,z1=-0.5,z2=0.5;
glBegin(GL_QUADS);
	    glColor3f(0.4,0.1,0.1);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi/2-5, z);
	glVertex3f(x+jarak , y + tinggi/2-5, z+lebar);
	glVertex3f(x+jarak , y, z+lebar);

    glVertex3f(x, y, z);//kiri
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x+z1 , y + tinggi, z+z1);
	glVertex3f(x+z1 , y, z+z1);
	    glVertex3f(x+jarak, y, z+lebar);//kanan
	glVertex3f(x+jarak, y + tinggi, z+lebar);
	glVertex3f(x+jarak+z2 , y + tinggi, z+lebar+z2);
	glVertex3f(x+jarak+z2 , y, z+lebar+z2);
		    glVertex3f(x+z2, y+tinggi-0.5, z);//atas
	glVertex3f(x+z2, y + tinggi, z);
	glVertex3f(x+jarak+z2 , y + tinggi, z+lebar);
	glVertex3f(x+jarak+z2 , y+tinggi-0.5, z+lebar);
glEnd();
while(y+tinggi-0.5>= 10.0){
        glBegin(GL_QUADS);
    glVertex3f(x+n1, y+tinggi-0.5, z);//
	glVertex3f(x+n2, y + tinggi-0.7, z);
	glVertex3f(x+jarak-n2 , y + tinggi-0.7, z+lebar);
	glVertex3f(x+jarak-n1 , y+tinggi-0.5, z+lebar);
glEnd();
y--;
y-=0.1;
}return;
}

void tangga(){
    float  y= -7.0 ,z =37,x=-17.0;
while(y >= -25.0){
    balok(-10,y,z,20,0.5,2.0);
     balok(x,y,-47.5,2.0,0.5,5.0);
    y--;
    z++;
    y-= 1;
    z+=1.5;
    x--;
    x-=1.5;
}
glBegin(GL_QUADS);
glTexCoord2f(0.0f, 0.0f);
glVertex3f(-10.0,-6,35.0);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(-10.0,5,35.0);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(-10.0,-10.0,52.0);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(-10.0,-20.0,52.0);
                    glTexCoord2f(0.0f, 0.0f);
            glVertex3f(10.0,-6,35.0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(10.0,5,35.0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(10.0,-10.0,52.0);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(10.0,-20.0,52.0);
glEnd();


return;
}

void ventilasi(float x,float y,float z,float panjang,float tinggi,float letak){
if (letak >0) {
glLineWidth(3.0);
glBegin(GL_LINE_LOOP);//kotak
glVertex3f(x,y,z);
glVertex3f(x,y+tinggi,z);
glVertex3f(x+panjang,y+tinggi,z);
glVertex3f(x+panjang,y,z);
glEnd();
glBegin(GL_LINE_LOOP);//Diamond
glVertex3f(x+panjang/4,y+tinggi/2,z);
glVertex3f(x+panjang/2,y+tinggi,z);
glVertex3f(x+panjang-(panjang/4),y+tinggi/2,z);
glVertex3f(x+panjang/2,y,z);
glEnd();
glBegin(GL_LINES);//silang
glVertex3f(x,y,z);
glVertex3f(x+panjang,y+tinggi,z);
glVertex3f(x,y+tinggi,z);
glVertex3f(x+panjang,y,z);
glEnd();
}else{
glBegin(GL_LINE_LOOP);//kotak
glVertex3f(x,y,z);
glVertex3f(x,y+tinggi,z);
glVertex3f(x,y+tinggi,z-panjang);
glVertex3f(x,y,z-panjang);
glEnd();
glBegin(GL_LINE_LOOP);//Diamond
glVertex3f(x,y+tinggi/2,z-panjang/4);
glVertex3f(x,y+tinggi,z-panjang/2);
glVertex3f(x,y+tinggi/2,z-panjang+(panjang/4));
glVertex3f(x,y,z-panjang/2);
glEnd();
glBegin(GL_LINES);//silang
glVertex3f(x,y,z);
glVertex3f(x,y+tinggi,z-panjang);
glVertex3f(x,y+tinggi,z);
glVertex3f(x,y,z-panjang);
glEnd();
}
}

void pintu(float x, float y, float z, float tinggi, float lebar,float letak){
    float jarak,n1,z1,z2;
    if (letak >0)
    jarak= 3.25, n1=0.3,z1=0.5,z2=-0.5;//n2=0.7
    else
    jarak= -3.25, n1=-0.3,z1=-0.5,z2=0.5;
glBegin(GL_QUADS);
	    glColor3f(0.4,0.1,0.1);
	glVertex3f(x, y, z);
	glVertex3f(x, y + tinggi/2, z);
	glVertex3f(x+jarak , y + tinggi/2, z+lebar);
	glVertex3f(x+jarak , y, z+lebar);

    glVertex3f(x, y, z);//kiri
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x+z1 , y + tinggi, z+z1);
	glVertex3f(x+z1 , y, z+z1);
	    glVertex3f(x+jarak, y, z+lebar);//kanan
	glVertex3f(x+jarak, y + tinggi, z+lebar);
	glVertex3f(x+jarak+z2 , y + tinggi, z+lebar+z2);
	glVertex3f(x+jarak+z2 , y, z+lebar+z2);
		    glVertex3f(x, y+tinggi-0.5, z);//atas
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x+jarak+z2 , y + tinggi, z+lebar);
	glVertex3f(x+jarak+z2 , y+tinggi-0.5, z+lebar);
glEnd();
	glColor4f(0.7,0.7,0.7,0.7);
while(y+tinggi-0.5>= 10.0){
        glBegin(GL_QUADS);
    glVertex3f(x, y+tinggi-0.5, z);//
	glVertex3f(x, y + tinggi-5, z);
	glVertex3f(x+jarak/2-n1 , y + tinggi-5, z+lebar/2-0.2);
	glVertex3f(x+jarak/2-n1 , y+tinggi-0.5, z+lebar/2-0.2);
            glVertex3f(x+jarak/2, y+tinggi-0.5, z+lebar/2+0.2);//
            glVertex3f(x+jarak/2, y + tinggi-5, z+lebar/2+0.2);
            glVertex3f(x+jarak , y + tinggi-5, z+lebar);
            glVertex3f(x+jarak , y+tinggi-0.5, z+lebar);
glEnd();
y--;
y-=4;
}return;
}

void furniture(){//sofa + meja+ lemari + TV +
    glColor3f(0.9,0.3,0.3);//sofa 1
balok(-39.0,-5.0,14.0,5.0,6.0,13.0);//alas// balok(x,y,z,panjang,tinggi,lebar)
glColor3f(0.8,0.1,0.1);
balok(-39.0,-5.0,15.0,1.0,12.0,15.0);//sandaran
glColor3f(0.6,0.1,0.1);
balok(-39.0,-5.0,15.0,5.0,8.0,1.0);
balok(-39.0,-5.0,1.0,5.0,8.0,1.0);

glColor3f(0.9,0.3,0.3);// sofa 2
balok(-31.0,-5.0,19.0,13.0,6.0,5.0);//alas
glColor3f(0.8,0.1,0.1);
balok(-32.0,-5.0,19.0,15.0,12.0,1.0);//sandaran
glColor3f(0.6,0.1,0.1);
balok(-32.0,-5.0,19.0,1.0,8.0,5.0);
balok(-18.0,-5.0,19.0,1.0,8.0,5.0);

glColor3f(0.9,0.3,0.3);//sofa 3
balok(-14.0,-5.0,10.0,5.0,6.0,5.0);//alas
glColor3f(0.8,0.1,0.1);
balok(-9.0,-5.0,11.0,1.0,12.0,7.0);//sandaran
glColor3f(0.6,0.1,0.1);
balok(-14.0,-5.0,11.0,5.0,8.0,1.0);
balok(-14.0,-5.0,5.0,5.0,8.0,1.0);

glColor3f(0.9,0.3,0.3);//sofa 4 & 5
balok(-32.0,-5.0,-8.0,6.0,6.0,5.0);//alas
balok(-24.0,-5.0,-8.0,6.0,6.0,5.0);//alas
glColor3f(0.8,0.1,0.1);
balok(-33.0,-5.0,-13.0,7.0,12.0,1.0);//sandaran
balok(-25.0,-5.0,-13.0,7.0,12.0,1.0);//sandaran
glColor3f(0.6,0.1,0.1);
balok(-33.0,-5.0,-8.0,1.0,8.0,5.0);
balok(-26.0,-5.0,-8.0,1.0,8.0,5.0);
balok(-25.0,-5.0,-8.0,1.0,8.0,5.0);
balok(-18.0,-5.0,-8.0,1.0,8.0,5.0);

//meja
    glColor4f(1,1,1,0.2);
    balok(-30.0,2.0,12.0,12.0,0.5,9.0);//alas
    glColor3f(0.4,0.1,0.1);
    balok(-30.0,-5.0,12.0,0.5,7.0,0.5);//kaki
    balok(-19.5,-5.0,12.0,0.5,7.0,0.5);
    balok(-30.0,-5.0,4.5,0.5,7.0,0.5);
    balok(-19.5,-5.0,4.5,0.5,7.0,0.5);
    ///lemari
    balok(-39.0,-5.0,-32.0,15.0,30.0,7.0);
       balok(-29.0,-5.0,-82.0,15.0,30.0,7.0);//rmh belakang
    glColor4f(1,1,1,0.2);
    balok(-38.0,0.0,-31.9,6,24.0,6.0);
    balok(-25.0,0.0,-31.9,-6,24.0,6.0);
        balok(-28.0,0.0,-81.9,6,24.0,6.0);//rumah belakang
    balok(-15.0,0.0,-81.9,-6,24.0,6.0);

    //TV
    glColor3f(0.4,0.1,0.1);//lemari tv
     balok(17.0,-5.0,-32.0,15.0,10.0,7.0);
     glColor4f(1,1,1,0.2);
    balok(17.0,-4,-31.9,6,8,6.0);
    balok(32.0,-4,-31.9,-6,8,6.0);
    glColor3f(0,0,0);//tv
    balok(19.0,5.0,-35.0,11.0,10 ,0.1);
    glColor4f(0.2,0.2,0.2,0.5);
    balok(19.5,5.5,-34.9,10.0,9,0.1);
}



void rumahadatbangkabelitung(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		//set cahaya
		GLfloat qaAmbientLight[] = {0.2,0.2,0.2,1.0};
		GLfloat qaDiffuseLight[] = {0.2,0.2,0.2,1.0};
		GLfloat qaSpecularLight[] = {0.2,0.2,0.2,1.0};
		glLightfv(GL_LIGHT1, GL_AMBIENT,qaAmbientLight);
		glLightfv(GL_LIGHT1,GL_DIFFUSE,qaDiffuseLight);
		glLightfv(GL_LIGHT1,GL_SPECULAR,qaSpecularLight);
		//posisi cahaya

		GLfloat cahaya[] = {-40,50,50,1};
		glLightfv(GL_LIGHT1,GL_POSITION,cahaya);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
//////////////////////////////START///////////////////////////////////////////////////////
////////////////////////jendela rumah utama////////////////////////////////
    glColor3f(0.4,0.1,0.1);
jendela(35.0,5,20.0,20.0,3.25,1.0);//depan
jendela(27.5,5,20.0,20.0,3.25,0.0);
jendela(20.0,5,20.0,20.0,3.25,1.0);
jendela(12.5,5,20.0,20.0,3.25,0.0);
jendela(-35.0,5,20.0,20.0,3.25,0.0);
jendela(-27.5,5,20.0,20.0,3.25,1.0);
jendela(-20.0,5,20.0,20.0,3.25,0.0);
jendela(-12.5,5,20.0,20.0,3.25,1.0);
jendela(-40.0,5,15.0,20.0,3.25,0.0);//kiri
jendela(-40.0,5,-5.5,20.0,3.25,0.0);
jendela(-40.0,5,-27.5,20.0,3.25,0.0);
jendela(-43.25,5,4.5,20.0,3.25,1.0);
jendela(-43.25,5,-17.5,20.0,3.25,1.0);
jendela(-43.25,5,-38.0,20.0,3.25,1.0);
jendela(40.0,5,15.0,20.0,3.25,1.0);//kanan
jendela(40.0,5,-5.5,20.0,3.25,1.0);
jendela(40.0,5,-27.5,20.0,3.25,1.0);
jendela(43.25,5,4.5,20.0,3.25,0.0);
jendela(43.25,5,-17.5,20.0,3.25,0.0);
jendela(43.25,5,-38.0,20.0,3.25,0.0);
///////////////////jendela rumah belakang//////////////////////////
jendela(-40.0,5,-62,20.0,3.25,0.0);//kiri
jendela(-40.0,5,-80,20.0,3.25,0.0);
jendela(-43.25,5,-73,20.0,3.25,1.0);
jendela(-43.25,5,-90.5,20.0,3.25,1.0);
jendela(40.0,5,-62,20.0,3.25,1.0);//kanan
jendela(40.0,5,-80,20.0,3.25,1.0);
jendela(43.25,5,-73,20.0,3.25,0.0);
jendela(43.25,5,-90.5,20.0,3.25,0.0);
///////////////////////ventilasi//////////////////////
    glColor3f(0.4,0.1,0.1);
ventilasi(-35.0,25.0,20.0,7.5,5,1);//depan
ventilasi(-20.0,25.0,20.0,7.5,5,1);
ventilasi(12.5,25.0,20.0,7.5,5,1);
ventilasi(27.5,25.0,20.0,7.5,5,1);
ventilasi(-5,25.0,20.0,10.0,5,1);//pintu
ventilasi(-5,25.0,-40.0,10.0,5,1);//pintu belakang
ventilasi(-5,25.0,-60.0,10.0,5,1);//pintu rumah belakang
ventilasi(-40.0,25.0,15.0,7.5,5,0);//kiri
ventilasi(-40.0,25.0,-5.5,9.0,5,0);
ventilasi(-40.0,25.0,-27.5,7.5,5,0);
ventilasi(-40.0,25.0,-62.5,7.5,5,0);
ventilasi(-40.0,25.0,-80.0,7.5,5,0);
ventilasi(40.0,25.0,15.0,7.5,5,0);//kanan
ventilasi(40.0,25.0,-5.5,9.0,5,0);
ventilasi(40.0,25.0,-27.5,7.5,5,0);
ventilasi(40.0,25.0,-62.5,7.5,5,0);
ventilasi(40.0,25.0,-80.0,7.5,5,0);
/////////////////////pintu//////////////////////////////
    glColor3f(0.4,0.1,0.1);
pintu(-8.25,-5.0,15.0,30.0,5.0,1);//depan
pintu(8.25,-5.0,15.0,30.0,5.0,0);
pintu(-5,-5.0,-40.0,30.0,5.0,0);//belakang
pintu(5,-5.0,-40.0,30.0,5.0,1);
pintu(-8.25,-5.0,-65.0,30.0,5.0,1);//rumah belakang
pintu(8.25,-5.0,-65.0,30.0,5.0,0);
/////////////////////////////tiang teras///////////////////////////////////
    glColor3f(0.4,0.1,0.1);
balok(-40.0,-5.0,35.0,1,35.0,1);
balok(39.0,-5.0,35.0,1,35.0,1);
balok(23,-5.0,35.0,1,35.0,1);
balok(-23,-5.0,35.0,1,35.0,1);
balok(10,-5.0,35.0,1,35.0,1);
balok(-11,-5.0,35.0,1,35.0,1);
///////////////////Furniture//////////////////////////
furniture();


////////////////////////////////////TEXTURE//////////////////////////////////////////////////
glColor3f(1,0.5,0.0);
//    	        glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureIdtikar);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

/////////////tikar
balok(15.0,-4.9,-30.0,20.0,0.2,-20);
balok(-35.0,-4.9,-30.0,20.0,0.2,-20);

//    	        glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureIdrumput);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//rumput
glColor3f(0,0.7,0.0);
balok(-50.0,-21.0,80.0,100.0,1.0,180.0);
////////////////////////////////////////Desain RUMAH///////////////////////////
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdkayu);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(0.4,0.2,0.2);
rumahbelakang(-40.0,-5.0,-60.0,80.0,45.0,30.0);///////////////////
rumahutama(-40.0,-5.0,20.0,80.0,45.0,60.0);///////////////////
//teras & lantai
	glColor3f(0.5,0.2,0.2);
balok(-40.0,-5.5,35.0,80.0,0.4,75.0);
balok(-15.0,-5.5,-40.0,30.0,0.4,20.0);
balok(-40.0,-5.5,-60.0,80.0,0.4,30.0);
glColor3f(1,1,1);
tangga();
///////////////////////////////////keliling rumah/////////////////////
//    	        glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureIdk);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(0.6,0.3,0.2);
balok(-40,-5.5,35.0,30.0,10.0,0.5);
balok(10.0,-5.5,35.0,30.0,10.0,0.5);
balok(-40,-5.5,35.0,0.5,10.0,15.0);
balok(39.5,-5.5,35.0,0.5,10.0,15.0);
balok(-15.0,-5.0,-40.0,0.5,10.0,7.5);//rumah belakang
balok(-15.0,-5.0,-52.5,0.5,10.0,7.5);
balok(14.5,-5.0,-40.0,0.5,10.0,20.0);
////    	        glEnable(GL_TEXTURE_2D);
////	glBindTexture(GL_TEXTURE_2D, _textureIdatap);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(0.2,0.2,0.2);
atap(-44.0,40.0,20.0,88.0,40.0,64.0,1);//rumah depan
atap(-44.0,40.0,-58.0,88.0,30.0,34.0,0);//rumah belakang

/////////////////////TIANG Rumah depan/////////////////////////////////
//   	        glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureIdtiang);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(0.5,0.5,0.5);
tiang(-40,-20.0,35.0,3.0,14.5,3.0);//depan
tiang(37.0,-20.0,35.0,3.0,14.5,3.0);
tiang(10.0,-20.0,35.0,3.0,14.5,3.0);
tiang(25.0,-20.0,35.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,35.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,35.0,3.0,14.5,3.0);
tiang(-40,-20.0,25.0,3.0,14.5,3.0);//depan2
tiang(37.0,-20.0,25.0,3.0,14.5,3.0);
tiang(10.0,-20.0,25.0,3.0,14.5,3.0);
tiang(25.0,-20.0,25.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,25.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,25.0,3.0,14.5,3.0);
tiang(-40,-20.0,-37.0,3.0,14.5,3.0);//belakang
tiang(-13.0,-20.0,-37.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,-37.0,3.0,14.5,3.0);
tiang(10.0,-20.0,-37.0,3.0,14.5,3.0);
tiang(25.0,-20.0,-37.0,3.0,14.5,3.0);
tiang(37.0,-20.0,-37.0,3.0,14.5,3.0);
tiang(37.0,-20.0,5.0,3.0,14.5,3.0);//tengah
tiang(-40,-20.0,5.0,3.0,14.5,3.0);
tiang(10.0,-20.0,5.0,3.0,14.5,3.0);
tiang(25.0,-20.0,5.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,5.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,5.0,3.0,14.5,3.0);
tiang(37.0,-20.0, -18.0,3.0,14.5,3.0);//tengah2
tiang(-40,-20.0,-18.0,3.0,14.5,3.0);
tiang(10.0,-20.0,-18.0,3.0,14.5,3.0);
tiang(25.0,-20.0,-18.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,-18.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,-18.0,3.0,14.5,3.0);
/////////////////////Tiang rumah belakang///////////////////////////////////
tiang(-40,-20.0, -60.0,3.0,14.5,3.0);//depan
tiang(37.0,-20.0,-60.0,3.0,14.5,3.0);
tiang(10.0,-20.0,-60.0,3.0,14.5,3.0);
tiang(25.0,-20.0,-60.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,-60.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,-60.0,3.0,14.5,3.0);
tiang(-40,-20.0, -73.0,3.0,14.5,3.0);//tengah
tiang(37.0,-20.0,-73.0,3.0,14.5,3.0);
tiang(10.0,-20.0,-73.0,3.0,14.5,3.0);
tiang(25.0,-20.0,-73.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,-73.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,-73.0,3.0,14.5,3.0);
tiang(-40,-20.0, -87.0,3.0,14.5,3.0);//belakang
tiang(37.0,-20.0,-87.0,3.0,14.5,3.0);
tiang(10.0,-20.0,-87.0,3.0,14.5,3.0);
tiang(25.0,-20.0,-87.0,3.0,14.5,3.0);
tiang(-13.0,-20.0,-87.0,3.0,14.5,3.0);
tiang(-27.0,-20.0,-87.0,3.0,14.5,3.0);

/////////////plat////////////////
//   	        glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureIdplat);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//balok(15,-19,70.0,20,20.0,0.5);


	glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void scale(int w, int h)
{
    if (h == 0) h= 1;

    glMatrixMode(GL_PROJECTION);
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, w/ h, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
}

void keyboard(int key, int x, int y)
{
    switch (key)
    {
	case GLUT_KEY_UP:
		glTranslatef(0.0, 0.0, 3.0);
		;break;
	case GLUT_KEY_RIGHT:
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case GLUT_KEY_DOWN:
        glTranslatef(0.0, 0.0, -3.0);
        break;
	case GLUT_KEY_LEFT:
        glTranslatef(-3.0, 0.0, 0.0);
        break;
	}
	rumahadatbangkabelitung();
}

void keyboard2(unsigned char key,int x,int y)
{
	switch (key)
	{
    case 'i':case 'I':
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, 1280/720, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -10.0);
        break;
    case '0':
    glMatrixMode(GL_PROJECTION);
      glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(50.0, 1280/720, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
        break;
	case '7':
        glTranslatef(0.0,3.0,0.0);
        break;
	case '9':
        glTranslatef(0.0,-3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,4.0);
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    rumahadatbangkabelitung();
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(40,0);
    glutCreateWindow("Rumah Adat Bangka Belitung, 672017081-672017091");
//    gambar();
    glutReshapeFunc(scale);
	glutDisplayFunc(rumahadatbangkabelitung);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(keyboard2);
    glutMainLoop();
    return 0;
}
