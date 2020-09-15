#include <boost/any.hpp>
#include <iostream>
#include <string>

using namespace std;

int main_test() {
	boost::any any;
	any = 10;
	cout << boost::any_cast<int>(any) << endl;
	//any = 10.01f;
	//cout << boost::any_cast<int>(any) << endl;
	any = 10.01f;
	cout << boost::any_cast<float>(any) << endl;
	//any = "abcd";
	//cout << boost::any_cast<char*>(any) <<endl;
	any = string("abcd");
	cout << boost::any_cast<string>(any) << endl;
	return 0;
}