//#include <iostream>
//#include<ctime>
//#include<thread>
//
//#include"A.hpp"
//using namespace std;
//
//#define THREADINGNUMS 500
//std::thread t[THREADINGNUMS];
//void threadfunc_1() {
//	for (int i = 0; i < 100000; i++) {
//		cout << "thread" << 0 << ":" << i << endl;
//	}
//}
//void multithreading_1() {
//	for (int i = 0; i < THREADINGNUMS; i++) {
//		t[i] = std::thread(threadfunc_1);
//		t[i].detach();
//	}
//}
//void threadfunc_2(int index) {
//	for (int i = 0; i < 100000; i++) {
//		cout << "thread"<< index<<":" << i << endl;
//	}
//}
//void multithreading_2(){	
//	for (int i = 0; i < THREADINGNUMS; i++) {
//		t[i] = std::thread(threadfunc_2,i);
//		t[i].detach();
//	}
//}
//int main() {
//	//A::runthreadfunc_1();
//	A a;
//	a.seta1(100);
//	for (int i = 0; i < THREADINGNUMS; i++) {
//		t[i] = std::thread(std::bind(&A::threadfunc_3,a));
//		t[i].detach();
//	}
//	system("pause");
//	return 0;
//}