#include "displayData.h"

displayData::displayData(float x, float y, float w, float h) 
{

	glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
     "Textures/numberCount.png",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
	this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    data = 0;

}

void displayData::draw() 
{
    float wd = w/3;
    int fac1, fac2, fac3;
    fac1 = data/100;
    fac2 = (data/10)%10;
    fac3 = data%10;



    
    glDisable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(.1*fac2, 0);
    glVertex2f(x+wd, y - h);
    
    glTexCoord2f(.1*fac2, 1);
    glVertex2f(x+wd, y);
    
    glTexCoord2f(.1*fac2+.1, 1);
    glVertex2f(x+wd+wd, y);
    
    glTexCoord2f(.1*fac2+.1, 0);
    glVertex2f(x+wd+wd, y - h);
    
    glEnd();


    
    glDisable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(.1*fac3, 0);
    glVertex2f(x+wd+wd, y - h);
    
    glTexCoord2f(.1*fac3, 1);
    glVertex2f(x+wd+wd, y);
    
    glTexCoord2f(.1*fac3+.1, 1);
    glVertex2f(x+wd+wd+wd, y);
    
    glTexCoord2f(.1*fac3+.1, 0);
    glVertex2f(x+wd+wd+wd, y - h);
    
    glEnd();

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(.1*fac1, 0);
    glVertex2f(x+.03, y - h);
    
    glTexCoord2f(.1*fac1, 1);
    glVertex2f(x+.03, y);
    
    glTexCoord2f(.1*fac1+.1, 1);
    glVertex2f(x+wd+.03, y);
    
    glTexCoord2f(.1*fac1+.1, 0);
    glVertex2f(x+wd+.03, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

void displayData::setData(int n)
{
    data = n;
}
