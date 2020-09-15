/*
ID: leeyupe1
LANG: C++11
PROG: ride
*/

//https://train.usaco.org/usacoprob2?a=HWhCyfwTnSl&S=ride
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define PROG ride
#define MARK
#ifdef MARK
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
int PROG() {
#ifdef MARK
	freopen(IN(PROG), "r", stdin);
	freopen(OUT(PROG), "w", stdout);
#endif
	string a;
	string b;
	cin >> a >> b;
	int alen = a.length();
	int blen = b.length();
	int avalue = 1, bvalue = 1;
	for (int i = 0; i < alen; i++)
	{
		avalue *= a[i] - 'A' + 1;
	}
	avalue %= 47;
	for (int i = 0; i < blen; i++)
	{
		bvalue *= b[i] - 'A' + 1;
	}
	bvalue %= 47;
	string ans;
	if (avalue == bvalue) { ans = "GO"; }
	else { ans = "STAY"; }
	cout << ans << endl;
	return 0;
}

//int main()
//{
//	return ride();
//}