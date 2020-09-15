/*
ID: leeyupeng
LANG: C++11
PROG: frac1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG frac1
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

class  Solution
{
private:
	struct Pair {
		int p0;
		int p1;
		bool operator<(const Pair& b) {
			if (p0 * b.p1 == p1 * b.p0) {
				return p0 < b.p0;
			}
			else {
				return p0 * b.p1 < p1 * b.p0;
			}
		}
	};
	int N;
	vector<Pair> vans;

public:
	void PROG() {
		cin >> N;
		vans.push_back({ 0,1 });
		vans.push_back({1,1});
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				vans.push_back({i,j});
			}
		}

		sort(vans.begin(), vans.end());

		cout << vans[0].p0 << "/" << vans[0].p1 << endl;
		for (int i = 1; i < vans.size(); i++) {
			if (vans[i - 1].p0 * vans[i].p1 == vans[i - 1].p1 * vans[i].p0) {
			}
			else {
				cout << vans[i].p0 << "/" << vans[i].p1 << endl;
			}
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