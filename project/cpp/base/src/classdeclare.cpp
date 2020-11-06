#include <iostream>
using namespace std;

//編譯報錯
//class A;
//class B;
//class A {
//public:
//	int a1;
//public:
//	void add(B b) {
//		a1 += b.b1;
//	}
//};
//class B {
//public:
//	int b1;
//public:
//	void add(A a) {
//		b1 += a.a1;
//	}
//};

class A;
class B;
class A {
public:
	int a1;
public:
	void add(B b);
};
class B {
public:
	int b1;
public:
	void add(A a);
};
void A::add(B b) {
	a1 += b.b1;
}
void B::add(A a) {
	b1 += a.a1;
}

//int main()
//{
//	A a;
//	B b;
//	a.a1 = 10;
//	b.b1 = 20;
//	a.add(b);
//	b.add(a);
//	cout << "a.a1 :" << a.a1 << endl;
//	cout << "b.b1 :" << b.b1 << endl;
//	system("pause");
//	return 0;
//}