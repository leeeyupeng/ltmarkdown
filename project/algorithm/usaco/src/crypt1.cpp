/*
ID: leeyupeng
LANG: C++11
PROG: crypt1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define PROG crypt1
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
bool IsPrimeCryptarithm(vector<int>& combine, set<int>& sn) {
	int a = combine[0] * 100 + combine[1] * 10 + combine[2];
	int b = combine[3] * 10 + combine[4];
	int p1 = a * combine[4];
	int p2 = a * combine[3];
	int p3 = a * b;
	if (p1 > 999) { return false; }
	while (p1 > 0) {
		if (sn.find(p1 % 10) == sn.end()) { return false; }
		p1 /= 10;
	}
	if (p2 > 999) { return false; }
	while (p2 > 0) {
		if (sn.find(p2 % 10) == sn.end()) { return false; }
		p2 /= 10;
	}
	while (p3 > 0) {
		if (sn.find(p3 % 10) == sn.end()) { return false; }
		p3 /= 10;
	}
	return true;
}
void Search(vector<int>& vn, set<int>& sn,vector<int>& combine, int n,int nums,int& ans) {
	if (nums == 5) {
		int a = combine[0] * 100 + combine[1] * 10 + combine[2];
		int b = combine[4] * 10 + combine[3];
		int p2 = a * combine[4];
		int p3 = a * b;
		if (p2 > 999) { return; }
		while (p2 > 0) {
			if (sn.find(p2 % 10) == sn.end()) { return; }
			p2 /= 10;
		}
		while (p3 > 0) {
			if (sn.find(p3 % 10) == sn.end()) { return; }
			p3 /= 10;
		}
		ans++;
		return;
	}
	if (nums == 4) {
		int a = combine[0] * 100 + combine[1] * 10 + combine[2];
		int p1 = a * combine[3];
		if (p1 > 999) { return; }
		while (p1 > 0) {
			if (sn.find(p1 % 10) == sn.end()) { return; }
			p1 /= 10;
		}
	}
	nums++;
	for (int i = 0; i < n; i++) {
		combine[nums-1] = vn[i];
		Search(vn,sn,combine,n,nums,ans);
	}
}
void PROG() {
	int n;
	cin >> n;
	vector<int> vn(n);
	set<int> sn;
	for (int i = 0; i < n; i++) {
		cin >> vn[i];
		sn.insert(vn[i]);
	}	

	int ans = 0;
	int nums = 0;
	vector<int> combine(5);
	Search(vn,sn, combine,n,nums,ans);
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