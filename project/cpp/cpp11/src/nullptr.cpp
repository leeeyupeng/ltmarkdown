#include <iostream>
using namespace std;
#include <cstddef>
class A {
private:
	int a1;
	int a2;
};

void foo(char *) {
	cout << "void foo(char *)" << endl;
}
void foo(int) {
	cout << "void foo(int)" << endl;
}

void foo2(char *) {
	cout << "void foo2(char *)" << endl;
}

void foo3(char *) {
	cout << "void foo3(char *)" << endl;
}
void foo3(int *) {
	cout << "void foo3(int *)" << endl;
}

void foo4(void *) {
	cout << "void foo4(void *)" << endl;
}
void foo4(char *) {
	cout << "void foo4(char *)" << endl;
}

void foo5(nullptr_t) {
	cout << "void foo5(nullptr_t)" << endl;
}
void foo5(void *) {
	cout << "void foo5(void *)" << endl;
}
void foo5(char *) {
	cout << "void foo5(char *)" << endl;
}

#define MYNULL ((void *)0)
int main_nullptr()
{
	{
		char *ch = NULL;
		A * ptra1 = NULL;
		foo(ch);
		foo((char*)NULL); 
		foo((char*)MYNULL);
		//foo((int)MYNULL);
		foo(nullptr);
		//foo((int)nullptr);
		foo((char *)(void *)NULL);
	}

	//{
	//	foo(nullptr);
	//}

	{
		foo2(0);
		//foo2(1);
		foo2(NULL);
		foo2(nullptr);
		//foo2(MYNULL);
	}

	{
		//foo3(nullptr);
		char *c = 0;
		//*c = 'a';
		foo3(c);

		int *i = nullptr;
		foo3(i);

		//foo3(nullptr);

		//foo3(NULL);
	}

	{
		foo4(MYNULL);
	}

	{
		A *a = NULL;
		A *a1 = (A*)MYNULL;
		A *a2 = nullptr;
		A *a3 = 0;
		//int i = (int)nullptr;
		//int i2 = (int)MYNULL;
		//int i3 = nullptr;



		foo4(a);
		foo4(a1);
		foo4(a2);
		foo4(a3);
		//foo4((void*)i);
	}

	{
		nullptr_t pp=nullptr;

		foo2(pp);
		foo5(pp);

	}
	system("PAUSE");
	return 0;
}