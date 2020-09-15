#include <iostream>
using namespace std;

class A {
private:
	int a1;
	int a2;
};
int main_decltype()
{
	{
		A *a;
		decltype(a) b;
	}

	{
		A *a;
		typedef decltype(a) aptr;
		aptr b;
	}

	{
		typedef decltype(nullptr) nullptrtype;
		//nullptrtype nullptr1 = NULL;
		nullptrtype nullptr1 = 0;
		//nullptrtype nullptr1 = 1;
		A *a = nullptr1;

		A *a1 = 0;

	}

	{
		void * ptr;
		typedef decltype(ptr) voidptrtype;
		voidptrtype voidptr = 0;
		A *a1 = (A*)voidptr;
		A *a2 = nullptr;

	}
	system("PAUSE");
	return 0;
}