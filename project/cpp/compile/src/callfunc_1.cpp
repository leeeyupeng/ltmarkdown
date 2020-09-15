
#include<stdio.h>
#include<stdlib.h>
int sum(int a, int b)
{
	int s[131072];
	int* heap = (int*)malloc(sizeof(int) * 262144*1024);
	int tmp = 0;
	tmp = a + b;
	return tmp;
}

int g1 = 100;
int main()
{
	int a = 10000;
	int b = 20;
	int ret = 0;



	int * ptra = (int *) malloc(sizeof(int));
	*ptra = a;
	int * ptrb = (int *)malloc(sizeof(int));
	*ptrb = b;

	ret = g1;
	ret = sum(a, b);
	//printf("ret=%d\n", ret);
	return 0;
}