/*
ID: leeyupeng
LANG: C++11
PROG: transform
*/

//https://train.usaco.org/usacoprob2?a=qnW1F7AiaQb&S=transform
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG transform
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

bool IsMatch(int n,vector<vector<char>>& vv1, vector<vector<char>>& vv2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vv1[i][j] != vv2[i][j]) { return false; }
		}
	}
	return true;
}
void Pattern1(int n, vector<vector<char>>& vv1, vector<vector<char>>& vv2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vv2[j][n-i-1] = vv1[i][j];
		}
	}
}
void Pattern2(int n, vector<vector<char>>& vv1, vector<vector<char>>& vv2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vv2[n-i-1][n-j-1] = vv1[i][j];
		}
	}
}
void Pattern3(int n, vector<vector<char>>& vv1, vector<vector<char>>& vv2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vv2[n - j - 1][i] = vv1[i][j];
		}
	}
}
void Pattern4(int n, vector<vector<char>>& vv1, vector<vector<char>>& vv2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vv2[i][n-j - 1] = vv1[i][j];
		}
	}
}
void PROG() {
	int n;
	cin >> n;
	vector<vector<char>> vv1(n);
	for (int i = 0; i < n; i++) {
		vv1[i].insert(vv1[i].begin(),n,' ');
		for (int j = 0; j < n; j++) {
			cin >> vv1[i][j];
		}
	}
	vector<vector<char>> vv2(n);
	for (int i = 0; i < n; i++) {
		vv2[i].insert(vv2[i].begin(), n, ' ');
		for (int j = 0; j < n; j++) {
			cin >> vv2[i][j];
		}
	}

	vector<vector<char>> vvtemp(n);
	for (int i = 0; i < n; i++) {
		vvtemp[i].insert(vvtemp[i].begin(), n, ' ');
	}

	vector<vector<char>> vvtemp2(n);
	for (int i = 0; i < n; i++) {
		vvtemp2[i].insert(vvtemp2[i].begin(), n, ' ');
	}

	int ans=7;
	while (true) {

		Pattern1(n,vv1,vvtemp);
		if (IsMatch(n, vvtemp, vv2)) {
			ans = 1;
			break;
		}
		Pattern2(n, vv1, vvtemp);
		if (IsMatch(n, vvtemp, vv2)) {
			ans = 2;
			break;
		}
		Pattern3(n, vv1, vvtemp);
		if (IsMatch(n, vvtemp, vv2)) {
			ans = 3;
			break;
		}
		Pattern4(n, vv1, vvtemp);
		if (IsMatch(n, vvtemp, vv2)) {
			ans = 4;
			break;
		}

		Pattern1(n, vvtemp, vvtemp2);
		if (IsMatch(n, vvtemp2, vv2)) {
			ans = 5;
			break;
		}
		Pattern2(n, vvtemp, vvtemp2);
		if (IsMatch(n, vvtemp2, vv2)) {
			ans = 5;
			break;
		}
		Pattern3(n, vvtemp, vvtemp2);
		if (IsMatch(n, vvtemp2, vv2)) {
			ans = 5;
			break;
		}

		if (IsMatch(n, vv1, vv2)) {
			ans = 6;
			break;
		}

		ans = 7;
		break;
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