/*
ID: leeyupeng
LANG: C++11
PROG: palsquare
*/

//https://train.usaco.org/usacoprob2?a=cJstVbQbAuG&S=palsquare
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG palsquare
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

void palsquaretobase(int n, int base, vector<int>& value) {
	while (n != 0) {
		value.push_back(n%base);
		n /= base;
	}
	reverse(value.begin(),value.end());
}
string palsquaretostring(vector<char>& vc,vector<int>& value){
	string res;
	for (int i = 0; i < value.size(); i++){
		res.push_back(vc[value[i]]);
	}
	return res;
}
bool palsquareIsPalindromic(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n >> 1; i++) {
		if (v[i] != v[n - i - 1]) { return false; }
	}
	return true;
}
void PROG() {
	int base;
	cin >> base;
	vector<int> vn;
	vector<int> vsquare;
	vector<char> vc = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N' };
	for (int i = 1; i <= 300; i++) {
		vn.clear();
		vsquare.clear();
		palsquaretobase(i * i,base, vsquare);
		if (palsquareIsPalindromic(vsquare)) {
			palsquaretobase(i, base, vn);
			cout << palsquaretostring(vc,vn)<<" "<<palsquaretostring(vc,vsquare)<<endl;
		}
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