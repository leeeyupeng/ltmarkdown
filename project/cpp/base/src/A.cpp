#include <iostream>

#include"A.hpp"

using namespace std;
void A::print() {
	cout << "A::print()" << endl;
}
void A::SetA1(int _a1) {
	a1 = _a1;
}
int A::GetA1() {
	return a1;
}
A::A() {
	cout << "A::A()" << endl;
}
A::~A() {
	cout << "A::~A()" << endl;
}