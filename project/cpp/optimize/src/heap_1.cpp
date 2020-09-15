#include <iostream>
using namespace std;

class A {
public:
	int a1;
	char a2;
	int a3;
	char a4;
};

class B {
public:
	int b1;
	char b2;
	int b3;
	char b4;
public:
	A* a5;
};
class C {
public:
	int c1;
	char c2;
	int c3;
	char c4;
public:
	B* b5;
};
int main1()
{
	int size = sizeof(A) + sizeof(B) + sizeof(C);
	char* p = (char*)malloc(size);
	memset(p, 0x0, size);
	C* c1 = new(p)C;
	c1->b5 = new(p + sizeof(C))B;
	c1->b5->a5 = new(p + sizeof(C) + sizeof(B))A;
	cout << "c1->c1 :" << c1->c1 << endl;
	cout << "c1->b5->b1:" << c1->b5->b1<<endl;
	cout << "c1->b5->a5->a1:" << c1->b5->a5->a1 << endl;
	system("pause");
	return 0;
}