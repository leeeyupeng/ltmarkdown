#include <iostream>
#include<ctime>

#include"declare"
using namespace std;

#define NUMS 1000000
int tt(){
	AA<int> a;
	cout << "sizeof(A):" << sizeof(AA<int>) << endl;
	cout << "sizeof(B):" << sizeof(B) << endl;

	packet_2<int>::type p;
	p = 10;

	cout << "sizeof(traits<int>):"<<sizeof(traits<int>) << endl;
	cout << "sizeof(traits2<int>):" << sizeof(traits2<int>) << endl;
	traits<int>::type t1;
	traits2<traits<int>::type>::type t2;
	typename traits<int>::type t3;
	typename traits2<traits<int>::type>::type t4;

	//typename traits<float>::type t5;
	cout << "sizeof(traits<float>::type):" << sizeof(traits<float>::type) << endl;
	
	system("pause");
	return 0;
}
int main() {
	tt();
}