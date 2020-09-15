/*
ID: leeyupe1
LANG: C++11
PROG: friday
*/

//https://train.usaco.org/usacoprob2?a=HWhCyfwTnSl&S=friday
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define PROG friday
#define MARK
#ifdef MARK
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
bool IsLeapYear(int year) {
	if (year % 100 == 0) { return year % 400 == 0; }
	else { return year % 4 == 0; }
}
void PROG() {
	int n;
	cin >> n;
	vector<int> ans{0,0,0,0,0,0,0};
	vector<int> month{0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int week = 1;
	for (int i = 1900; i < 1900 + n; i++){
		for (int j = 1; j <= 12; j++) {
			ans[(week + 6) % 7]++;
			week += month[j];
			if (j == 2 && IsLeapYear(i)) {
				week++;
			}
			week %= 7;
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << ans[i];
		if (i != 6) { cout << " "; }
	}
	cout << endl;
}

//int main()
//{
//#ifdef MARK
//	freopen(IN(PROG), "r", stdin);
//	freopen(OUT(PROG), "w", stdout);
//#endif
//	PROG();
//	return 0;
//}