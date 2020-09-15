#include <iostream>
#include"A.hpp"
#include"B.hpp"
#include<iostream>
#include<ctime>
using namespace std;

#define NUMS 1000000
int memory(){
	cout << "sizeof(A):" << sizeof(A) << endl;
	cout << "sizeof(B):" << sizeof(B) << endl;
	{
		int *i;
		i = new int[100];
		char **chars = new char*[NUMS];
		A **a= new A*[NUMS];
		B **b= new B*[NUMS];
		clock_t start, finish;
		start = clock();

		for (int i = 0; i < NUMS; i++) {
			a[i] = new A();
			b[i] = new B();
		}

		for (int i = 0; i < NUMS; i++) {
			delete a[i];
			delete b[i];
		}

		finish = clock();
		cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
	}

	{
		A* a;
		B* b;
		clock_t start, finish;
		start = clock();

		a = new A[NUMS];
		b = new B[NUMS];

		delete a;
		delete b;

		finish = clock();
		cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
	}


	{
		A* a;
		B* b;
		clock_t start, finish;
		start = clock();
		void* m = (void*)malloc(sizeof(A) * NUMS + sizeof(B) * NUMS);
		a = (A*)m;
		b = (B*)((A*)m + NUMS);

		for (int i = 0; i < NUMS; i++) {
			new ((void*)&a[i])A;
			new ((void*)&b[i])B;
		}
		for (int i = 0; i < NUMS; i++) {
			a[i].~A();
			b[i].~B();
		}
		free(m); 
		finish = clock();
		cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;
	}
	system("pause");
	return 0;
}
//int main() {
//	memory();
//}