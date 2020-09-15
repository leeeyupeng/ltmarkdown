//main.cpp 
#include <stdio.h>
#include <stdlib.h>

extern "C" int test_(int a, int b, int c);

int main()
{
	int a = 10;
	int b = 20;
	int c = 19;
	int sum = test_(a, b, c);
	printf("c = %d\n", sum);

	unsigned char ca = 255;
	unsigned char cb = 255;
	unsigned short sc = ca * cb;
	printf("sc = %d\n", sc);
	system("pause");
	return 0;
}