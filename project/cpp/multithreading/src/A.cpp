#include<iostream>
#include<thread>
using namespace std;
#include"A.hpp"
#define THREADINGNUMS 500
void A::seta1(int _a1) {
	a1 = _a1;
}
int A::geta1() {
	return a1;
}
void A::print() {
}
void A::threadfunc_1() {
	{
		for (int i = 0; i < 100000; i++) {
			cout << "thread" << 1 << ":" << i << endl;
		}
	}
}
void A::runthreadfunc_1()
{
	std::thread t[THREADINGNUMS];
	for (int i = 0; i < THREADINGNUMS; i++) {
		t[i] = std::thread(A::threadfunc_1);
		t[i].detach();
	}
}
void A::threadfunc_2(int index) {
	{
		for (int i = 0; i < 100000; i++) {
			cout << "thread" << index << ":" << i << endl;
		}
	}
}
void A::threadfunc_3() {
	for (int i = 0; i < 100000; i++) {
		cout << "threadfunc_" << 3 << ":" << i << "geta1():"<< geta1() << endl;
		seta1(i);
	}
}