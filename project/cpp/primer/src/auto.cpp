#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class A {
private:
	int a1;
	float a2;
public:
	void seta1(int _a1) { a1 = _a1; }
	void print() {
		cout << "a1:" << a1 << endl;
	}
};
class B {
private:
	int b1;
	float b2;
public:
	void setb1(int _b1) { b1 = _b1; }
	void print() {
		cout << "b1:" << b1 << endl;
	}
};

template<class T1,class T2>
auto add(T1 a, T2 b) {
	return a + b;
}
int main_auto() {
	auto a = A();
	auto b = B();
	a.seta1(10);
	b.setb1(100);
	a.print();
	b.print();

	auto c1 = add(10,10.2f);
	cout << "c1:" << c1 << endl;

	int arr[100];

	//for (int i = 0; i < 100; i++) {
	//	arr[i] = i;
	//}
	int i = 0;
	//for (auto e : arr) {
	//	e = i++;
	//}
	for (auto& e : arr) {
		e = i++;
	}
	
	for (auto e : arr) {
		cout << "e:" << e << endl;
	}

	system("PAUSE");
	return 0;
}