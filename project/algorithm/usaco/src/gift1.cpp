/*
ID: leeyupe1
LANG: C++11
PROG: gift1
*/

//https://train.usaco.org/usacoprob2?a=HWhCyfwTnSl&S=gift1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
#define PROG gift1
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
	int np;
	cin >> np;
	vector<string> vnpname(np);
	map<string, int> mnpname;
	for (int i = 0; i < np; i++) {
		cin >> vnpname[i];
		mnpname.insert({ vnpname[i] ,i});
	}
	vector<int> vm(np,0);

	for (int i = 0; i < np; i++) {
		string name;
		cin >> name;
		int mnums, nnums;
		cin >> mnums >> nnums;
		if (nnums == 0) {continue;}
		vm[mnpname[name]] -= mnums - mnums % nnums;
		for (int j = 0; j < nnums; j++) {
			string nname;
			cin >> nname;
			vm[mnpname[nname]] += mnums / nnums;
		}
	}

	for (int i = 0; i < np; i++) {
		cout << vnpname[i] << " " << vm[i] << endl;
	}

	return 0;
}

//int main()
//{
//	return PROG();
//}