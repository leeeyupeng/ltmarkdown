/*
ID: leeyupeng
LANG: C++11
PROG: namenum
*/

//https://train.usaco.org/usacoprob2?a=ynnR1niIA9O&S=namenum
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define PROG namenum
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

void Search(set<string>& dict, vector<vector<char>> vv, vector<string>& ans,string& in,string& name,int index) {
	int num = in[index] - '0';
	for (int i = 0; i < vv[num].size(); i++) {
		name.push_back(vv[num][i]);
		if (index == in.size() - 1) {
			if (dict.find(name) != dict.end()) {
				ans.push_back(name);
			}
		}
		else {
			Search(dict,vv, ans,in,name,index+1);
		}
		name.pop_back();
	}
}
void PROG() {
	vector<vector<char>> vv{
	{},
	{},
	{ 'A','B','C' },
	{ 'D','E','F' },
	{ 'G','H','I' },
	{ 'J','K','L' },
	{ 'M','N','O' },
	{ 'P','R','S' },
	{ 'T','U','V' },
	{ 'W','X','Y' },
	};
	string in;
	cin >> in;
	set<string> dict;
	ifstream fin("dict.txt");
	string temp;
	while (!fin.eof()) {
		fin >> temp;
		dict.insert(temp);
	}
	string name;
	vector<string> ans;
	Search(dict, vv, ans,in,name,0);
	if (ans.empty()) {
		cout << "NONE" << endl;
	}
	else{
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
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