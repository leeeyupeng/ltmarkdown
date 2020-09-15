#ifndef _B
#define _B
class A;
class B {
private:
	A a;
public:
	A toa();

	A toa2() { return A(); }
};
#endif