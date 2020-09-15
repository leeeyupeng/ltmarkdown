#include <stdio.h>

#include"shape.h"
int main(int argc, char** argv)
{
	Shape* s[3];
	s[1] = CreateCircle(10.0f);
	printf("the area is %f \n", s[1]->area(s[1]));
	printf("the area is %f \n", CFUNC(s[1],area));
	return 0;
}