/*
ID: leeyupeng
LANG: C++11
PROG: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG dualpal
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
void dualpaltobase(int n, int base, vector<int>& value) {
	while (n != 0) {
		value.push_back(n%base);
		n /= base;
	}
	reverse(value.begin(), value.end());
}
bool dualpalIsPalindromic(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n >> 1; i++) {
		if (v[i] != v[n - i - 1]) { return false; }
	}
	return true;
}
void PROG() {
	int n, s;
	cin >> n >> s;
	int i = 0;
	int j = s + 1;
	vector<int> vbase;
	int num = 0;
	while (i<n&&j<=INT32_MAX)
	{
		num = 0;
		for (int k = 2; k <= 10; k++) {
			dualpaltobase(j,k,vbase);
			if (dualpalIsPalindromic(vbase)) {
				num++;
			}
			vbase.clear();
		}
		if (num>=2) {
			cout << j << endl;
			i++;
		}
		j++;
	}
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