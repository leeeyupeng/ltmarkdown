#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include "shape.h"
const double PI = 3.1415926;
void circleconstruct(void *self,double r) {
	Circle* c = (Circle*)self;
	CircleData* d = (CircleData*)malloc(sizeof(CircleData));
	assert(d != NULL);
	d->radius = r;
	c->shapedata = d;
}
static double circlearea(void *self) {
	Circle* c = (Circle*)self;
	CircleData* d = (CircleData*)c->shapedata;
	return PI * d->radius * d->radius;
}
void circledestruct(void *self) {
	Circle* c = (Circle*)self;
	CircleData* d = (CircleData*)c->shapedata;
	free(d);
	d = NULL;
}
Circle* CreateCircle(double r)
{
	Circle* circle = (Circle*)malloc(sizeof(Circle));
	assert(circle != NULL);
	assert(r>0);
	circle->circle = circleconstruct;
	circle->area = circlearea;
	circle->release = circledestruct;

	circle->circle(circle);
	return circle;
}

void DeleteCircle(Circle* c)
{
}