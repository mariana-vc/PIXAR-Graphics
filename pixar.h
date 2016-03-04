/*
 * pixar.h
 *
 *  Created on: Nov 3, 2014
 *      Author: bhargavvar
 */

#ifndef PIXAR_H_
#define PIXAR_H_

//void gluCylinder(GLUquadric*  quad,  GLdouble  base,  GLdouble  top,  GLdouble  height,  GLint  slices,  GLint  stacks);
//void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
//void glutWireCone(GLdouble base, GLdouble height,  GLint slices, GLint stacks);
#include <iostream>
#include "stdio.h"
#include <cstdlib>
#include <stdlib.h>
#include <GL/gl.h>

#include "string.h"
#include <GL/glu.h>
#include "math.h"
#include <vector>
#include <iostream>

#include "readData.h"
#include "texture.h"


using namespace std;

typedef vector< int > vi;
typedef vector< float > vf;


const float PI = 3.1415926535f;


typedef struct balls{
	vf pos;
	vf vel;
	float rad;

}balls;

typedef struct slamp{
	vf posb;
	vf ang;
}slamp;

typedef struct blamp{
	vf posb;
	vf ang;
}blamp;

typedef struct uni{
	balls* ball;
	slamp* lamp2;
	blamp* lamp1;

}uni;

void cons(uni * p);
vf mem();

void memory(uni* uni);
struct zeromemory_t{};
extern  const zeromemory_t zeromemory;


void* _cdecl operator new(size_t cbSize, const zeromemory_t&);

void ball();
void cylinder(int r);
void sphere(int r);





#endif /* PIXAR_H_ */
