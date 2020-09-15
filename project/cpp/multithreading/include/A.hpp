#pragma once
class A {
private:
	int a1;
	int a2;
	char a3;
	int a4;
public:
	void seta1(int _a1);
	int geta1();
	void print();
	
	static void threadfunc_1();
	static void runthreadfunc_1();
	static void threadfunc_2(int index);
	void threadfunc_3();	
};