/*
ID: leeyupeng
LANG: C++11
PROG: milk2
*/

//https://train.usaco.org/usacoprob2?a=HWhCyfwTnSl&S=beads
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG milk2
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define MAX 1000002
void PROG() {
	int n;
	cin >> n;
	vector<int[2]> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0]>>v[i][1];
	}	
	vector<bool> vans(MAX,false);
	for (int i = 0; i < n; i++) {
		for (int j = v[i][0]; j < v[i][1]; j++) {
			vans[j] = true;
		}
	}

	int ans1=0, ans2=0;
	int start = 0, end = 0;
	for (int i = 0; i < MAX; i++) {
		if (vans[i]) { start = i; break; }
	}
	for (int i = MAX - 1; i >= 0; i--) {
		if (vans[i]) { end = i; break; }
	}
	int startindex = start;
	int i;
	for (i= start; i <= end; i++) {
		if (vans[i] != vans[startindex]) {
			if (vans[startindex] == true) {
				ans1 = max(ans1,i - startindex);
			}
			else {
				ans2 = max(ans2, i - startindex);
			}
			startindex = i;
		}
	}
	if (vans[startindex] == true) {
		ans1 = max(ans1, i - startindex);
	}
	else {
		ans2 = max(ans2, i - startindex);
	}
	startindex = i;
	cout << ans1 << " " << ans2 << endl;
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