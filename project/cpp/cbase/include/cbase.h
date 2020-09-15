#ifndef SHAPE_H
#define SHAPE_H
#define CFUNC(c,func) c->func(c)
typedef struct
{
	void *shapedata;
	void(*shape)(void *);
	double(*area)(void *);
	void(* release)(void *);
}Shape;
typedef struct
{
	double radius;
}CircleData;
typedef struct
{
	void *shapedata;
	void(*circle)(void *);
	double (*area)(void *);
	void (*release)(void *);
}Circle;
Circle* CreateCircle(double r);
void DeleteCircle(Circle* c);

typedef struct
{
	double length;
	double width;
}SquareData;
typedef struct
{
	void *shapedata;
	double(*area)(void *);
	void(*release)(void *);
}Square;
//Square* CreateSquare(double l, double w);

#endif