/*
ID: leeyupeng
LANG: C++11
PROG: pprime
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define PROG pprime
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define MAX 100000000
class  Solution
{
private:
	int amin, bmax;
	vector<int> vPalindromes;
	void DFS(int nums, int index,int v) {
		if (nums == index) {
			vPalindromes.push_back(v);
		}
		else {
			if (index == 0) {
				for (int i = 1; i <= 9; i++) {
					DFS(nums, index + 1, i);
				}
			}
			else {
				for (int i = 0; i <= 9; i++) {
					DFS(nums, index + 1, v * 10 + i);
				}
			}
		}
	}
	void InitPalindromes(int a, int b) {
		amin = a;
		bmax = b;
		vPalindromes.clear();
		int adigit = 0, bdigit = 0;
		while (a != 0) {
			adigit ++;
			a /= 10;
		}
		while (b != 0) {
			bdigit ++;
			b /= 10;
		}
		for (int i = (adigit + 1) / 2; i <= (bdigit + 1) / 2; i++) {
			DFS(i, 0,0);
		}
	}
	bool IsPrime(int p) {
		int s = sqrt(p);
		for (int i = 2; i <= s; i++) {
			if (p%i == 0) { return false; }
		}
		return true;
	}
public:
	void PROG() {
		int a, b;
		cin >> a >> b;
		if (b == 100000000) { b--; }
		InitPalindromes(a,b);
		int size = vPalindromes.size();

		vector<int> vans;
		for (int i = 0; i < size; i++) {
			int v = vPalindromes[i];

			{
				int p = v;
				int m = v;
				while (m != 0) {
					p = p * 10 + m % 10;
					m /= 10;
				}
				if (p >= a && p <= b && IsPrime(p)) {
					vans.push_back(p);
				}
			}

			{
				int p = v;
				int m = v/10;
				while (m != 0) {
					p = p * 10 + m % 10;
					m /= 10;
				}

				if (p >= a && p <= b && IsPrime(p)) {
					vans.push_back(p);
				}
			}
		}

		sort(vans.begin(), vans.end());
		for (int i = 0; i < vans.size(); i++) {
			cout << vans[i] << endl;
		}
	}
};

//int main()
//{
//#ifdef FILESTREAM
//	freopen(IN(PROG), "r", stdin);
//	freopen(OUT(PROG), "w", stdout);
//#endif
//	Solution s;
//	s.PROG();
//	return 0;
//}