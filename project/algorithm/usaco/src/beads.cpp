/*
ID: leeyupe1
LANG: C++11
PROG: beads
*/

//https://train.usaco.org/usacoprob2?a=HWhCyfwTnSl&S=beads
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG beads
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

void PROG() {
	int n;
	cin >> n;
	string necklace;
	cin >> necklace;
	int ans = 0;
	int curstart=0;
	int curnums=0;
	int lastnums = 0;
	int startnums = -1;
	int startnums2 = -1;
	int startindex = 0;
	int wnums = 0;
	int lastwnums = 0;
	int i = 0;
	while (i < n)
	{
		if (necklace[curstart] == 'w') {
			if (necklace[i] != 'w') {
				startindex = i;
				curstart = i;
			}
		}
		else if (necklace[i] == 'w') {
			wnums++;
		}
		else if(necklace[i] == necklace[curstart]) {
			wnums = 0;
		}
		else {
			curnums = i - curstart;
			if (startnums == -1) { 
				startnums = curnums; }
			else if (startnums2 == -1) { 
				startnums2 = curnums; }
			ans = max(ans, curnums + lastnums);
			lastnums = curnums + lastwnums;
			lastwnums = wnums;
			wnums = 0;
			curstart = i;
		}
		i++;
	}	
	
	if (startnums2 == -1) {
		ans = n;
	}
	else if (necklace[startindex] == necklace[curstart]) {
		curnums = n - curstart + startindex + startnums;
		ans = max(ans, curnums + lastnums);
		ans = max(ans, curnums + lastwnums + startnums2);
	}
	else {
		curnums = n - curstart + startindex;
		ans = max(ans, curnums + lastnums);
		ans = max(ans, curnums + lastwnums + startnums);
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