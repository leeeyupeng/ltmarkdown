/*
ID: leeyupeng
LANG: C++11
PROG: barn1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG barn1
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

void PROG() {
	int m, s, c;
	cin >> m >> s >> c;
	vector<int> vc(c);
	for (int i = 0; i < c; i++) {
		cin >> vc[i];
	}
	sort(vc.begin(),vc.end());
	vector<int> vcc(c-1);
	for (int i = 0; i < c - 1; i++) {
		vcc[i] = vc[i + 1] - vc[i] - 1                                                                                                                                                                                                                                                                       ;
	}
	sort(vcc.begin(), vcc.end());
	int ans = vc[c - 1] - vc[0] + 1;
	for (int i = 0; i < m - 1 && c-1-1-i>=0; i++)
	{
		ans -= vcc[c - 1 - 1 - i];
	}
	cout << ans << endl;
}

//int main()
//{
//#ifdef FILESTREAM
//	freopen(IN(PROG), "r", stdin);
//	freopen(OUT(PROG), "w", stdout);
//#endif
//	PROG();
//	return 0;
//}