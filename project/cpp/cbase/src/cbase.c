#include <stdio.h>

#include"cdefine.h"
MAX(a,b)
int main(int argc, char** argv)
{
	printf("MAX(a,b):%d\n", max(10,50));

	int a = 100, b = 200;
	printf("swap(a,b):%d %d\n", a,b);
	swap(&a, &b, int);
	printf("swap(a,b):%d %d\n", a, b);
	return 0;
}