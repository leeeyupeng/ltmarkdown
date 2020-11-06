#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

//[capture](parameters) mutable ->return-type{statement}

class A {
private:
	int a1;
	int a2;
public:
	int (*lambda)();

	std::function<int()> flambda;
public:
	A() :A(0, 0) {}
	A(int _a1, int _a2) :a1(_a1), a2(_a2) { 
		//lambda = [this]()->int {return this->a1 + this->a2; };
	}
	void seta1(int _a1) { a1 = _a1; }
	void seta2(int _a2) { a2 = _a2; }
	void lambdaplus() {
		auto func = [this]()->int {return this->a1 + a2; };
		auto funcvalue = func();
		cout << "funcvalue:" << funcvalue << endl;
	}

	void setlambda() {
		auto func = []()->int {return 10 + 100; };
		lambda = func;
	}

	void setflambda() {
		auto func = [this]()->int {return this->a1 + this->a2; };
		flambda = func;
	}

	auto getflambda()->decltype(flambda) {
		auto func = [this]()->int {return this->a1 + this->a2; };
		return func;
	}
};

std::function<int()> testlambda()
{
	std::function<int()> fflambda;
	{
		A a(10, 100);
		fflambda = a.getflambda();
		auto fvalue1 = fflambda();
		cout << "fvalue1:" << fvalue1 << endl;
		a.seta1(20);
		a.seta2(200);
		auto fvalue2 = fflambda();
		cout << "fvalue2:" << fvalue2 << endl;

		a.seta1(-20);
		a.seta2(-200);
	}
	return fflambda;
}
int main_lambda() {
	//{
	//	auto plus = [](int a, int b) -> int { return a + b; };
	//	auto add = plus(10, 100);
	//	cout << "add:" << add << endl;
	//	//auto add2 = plus(100,"abc");
	//}
	//{
	//	int capture = 1;
	//	auto lambdaplus = [capture](int a, int b)->int {return  capture + a + b; };
	//	cout << "lambdaplus:" << lambdaplus(10, 100) << endl;
	//}
	//{
	//	int capture = 1;
	//	auto lambdaplus = [](int a, int b)->int {return  capture + a + b; };
	//	cout << "lambdaplus:" << lambdaplus(10, 100) << endl;
	//}
	//{
		//{
		//	int capture = 1;
		//	auto lambdaplus = [capture](int a, int b)->int {return  capture + a + b; };
		//	cout << "lambdaplus:" << lambdaplus(10, 100) << endl;
		//	capture = 2;
		//	cout << "lambdaplus:" << lambdaplus(10, 100) << endl;
		//}

		//{
		//	int capture = 1;
		//	auto lambdaplus = [=](int a, int b)->int {return  capture + a + b; };
		//	cout << "lambdaplus:" << lambdaplus(10, 100) << endl;
		//}
	//}
	//{
	//	A a(10,100);
	//	a.lambdaplus();
	//	a.seta1(20);
	//	a.seta2(200);
	//	a.lambdaplus();
	//}

	//{
	//	A a(10,100);
	//	a.setflambda();
	//	auto fvalue1 = a.flambda();
	//	cout << "fvalue1:" << fvalue1 << endl;
	//	a.seta1(20);
	//	a.seta2(200);
	//	auto fvalue2 = a.flambda();
	//	cout << "fvalue2:" << fvalue2 << endl;
	//}

	//lambda����ʽʹ���������ĵľֲ����� ������ǰ�����ĵ��� ��Ȼ����
	//{
	//	std::function<int()> fflambda;

	//	{
	//		A a(10, 100);
	//		fflambda = a.getflambda();
	//		auto fvalue1 = fflambda();
	//		cout << "fvalue1:" << fvalue1 << endl;
	//		a.seta1(20);
	//		a.seta2(200);
	//		auto fvalue2 = fflambda();
	//		cout << "fvalue2:" << fvalue2 << endl;

	//		a.seta1(-20);
	//		a.seta2(-200);
	//	}
	//	A a1(-10, -100);
	//	A a2(-10, -100);
	//	A a3(-10, -100);
	//	auto fvalue3 = fflambda();
	//	cout << "fvalue3:" << fvalue3 << endl;
	//}
	//A a11(-10, -100);
	//A a12(-10, -100);
	//A a13(-10, -100);

	//lambda����ʽʹ���������ĵľֲ����� ������ǰ�����ĵ��� ���ʵ�this�ڴ��ַ ��ʵ�Ѿ����� �����쳣
	//{
	//	std::function<int()> fflambda;
	//	fflambda = testlambda();
	//	A aa[100];
	//	auto fvalue3 = fflambda();
	//	cout << "fvalue3:" << fvalue3 << endl;
	//}

	system("PAUSE");
	return 0;
}