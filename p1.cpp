/*
 * p1.cpp
 *
 *  Created on: Nov 3, 2014
 *      Author: bhargavvar
 */

#include "pixar.h"
#include <GL/glut.h>
GLuint _textureId;

//uni* uni= new uni;

vf mem(){
	vf p=vf(3,0);
	return p;
}

void memory(uni* uni1){
	 uni1=new (zeromemory) uni();
	uni1->ball=new (zeromemory) balls();
	uni1->lamp1=new (zeromemory) blamp();
	uni1->lamp2=new (zeromemory) slamp();
	(uni1->ball->vel)=mem();
	(uni1->ball->pos)= mem();
	uni1->ball->pos[0]=-20;uni1->ball->pos[1]=0;uni1->ball->pos[2]=2;
	uni1->ball->vel[0]=0.2;uni1->ball->vel[1]=0;uni1->ball->vel[0]=0;
	(uni1->lamp1->posb)= mem();;
	(uni1->lamp1->ang)= mem();

	(uni1->lamp2->posb)= mem();
	uni1->lamp2->posb[0]=4;uni1->lamp2->posb[1]=0;uni1->lamp2->posb[2]=-8;
	(uni1->lamp2->ang)=mem();


}

const zeromemory_t zeromemory;
void* _cdecl operator new(size_t cbSize, const zeromemory_t&)
{
    void *mem = ::operator new(cbSize);
    memset(mem,0,cbSize);
    return mem;
}
void ball(){
	glPushMatrix();
	//glColor3f(1,2,3);
	glTranslatef(3,1.5,4);
	Image* image1 = loadImage("BeachBallColor.bmp");
					_textureId = readTexture(image1);

					delete image1;

	GLUquadricObj* sphere = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(sphere,1);

	gluSphere(sphere,1.5,32,32);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
void cylinder(int r){
	GLUquadricObj *obj1 = gluNewQuadric();
	switch(r){
	case 1:
		glPushMatrix();
		glRotatef(-90,1,0,0);
		gluCylinder(obj1,3, .7, 1.5,99,100);
		glPopMatrix();
		glTranslatef(0,1.6,0);
		break;
	case 2:
		glPushMatrix();
		glRotatef(-90,1,0,0);
		glColor3f(0,0,1);
		gluCylinder(obj1,.55,.55,5,99,100);
		glPopMatrix();
		glTranslatef(0,5.1,0);
		break;
	case 3:
		glPushMatrix();
		glRotatef(90,-1,0,0);
		glColor3f(0,0,1);
		gluCylinder(obj1,.5, .5, 4,99,100);
		glPopMatrix();
		glTranslatef(0,4,0);
		break;



	}

}
void sphere(int r){
	GLUquadricObj *obj1 = gluNewQuadric();
	switch(r){
	case 1:
		glPushMatrix();
		glColor3f(0,1,0);
		glutSolidSphere(1,10,10);
		glPopMatrix();
		glTranslatef(0,.1,0);
		break;
	case 2:
		glPushMatrix();
		glColor3f(0,1,0);
		glutSolidSphere(.7,10,10);
		glPopMatrix();
		glTranslatef(0,0,0);

		break;
	case 3:
		glPushMatrix();
		//		GLfloat light1_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

				GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
				GLfloat light1_specular[] = { 0.5, 0.0, 0.0, 1.0 };

				GLfloat light1_position[] = { 0,1,0, 1.0 };

				GLfloat spot_direction[] = { 1.0, 1.0, 1.0 };

		//		glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
			    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
				glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
				glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
				glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
				glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
				glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);
				glMaterialf(GL_FRONT, GL_SHININESS, 10.0);
		glTranslatef(0,.9,0);
		glColor3f(0,1,0);
		glutSolidSphere(.8,10,10);
		glTranslatef(0,-.9,0);

		glRotatef(90,-1,0,0);
		glColor3f(0,0,1);
		gluCylinder(obj1,.55, 2, 2,99,100);
		glPopMatrix();
		break;
	}
}
void cons(uni* p){
	if(p->lamp1->ang[1]>30){
		if(p->lamp1->ang[2]>=60){
			p->lamp1->ang[1]=30;
		}
		else{
		p->lamp1->ang[2]+=p->lamp1->ang[2]-30;}
	}
	else if(p->lamp1->ang[1]<30){
		if(p->lamp1->ang[2]>0){
			p->lamp1->ang[2]+=p->lamp1->ang[2]-30;
		}
		else{
			p->lamp1->ang[2]=0;
		}
	}
	else if(p->lamp1->ang[1]<=0){
		p->lamp1->ang[1]=0;
		p->lamp1->ang[2]=0;
	}
	if(p->lamp1->ang[2]<=0){
		p->lamp1->ang[2]=0;
	}
//ball
	if(-45>p->ball->pos[0] ||p->ball->pos[0]>45){
		p->ball->vel[0]= -1*p->ball->vel[0];
	}
	if(-45>p->ball->pos[2] ||p->ball->pos[2]>45){
			p->ball->vel[2]= -1*p->ball->vel[2];
		}


}
