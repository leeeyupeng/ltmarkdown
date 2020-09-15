/*
ID: leeyupeng
LANG: C++11
PROG: hamming
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG hamming
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define NMAX 64
#define BMAX 8
#define DMAX 7
class  Solution
{
private:
	int N;
	int B;
	int D;
	int bmax;
	int map[256][256];
	vector<int> vans;
	char getDistance(int a, int b) {
		int ans = 0;
		for (int i = 0; i < B; i++) {
			if (((a & 0x1) ^ (b & 0x1)) == 1) { ans++; }
			a=a >> 1; b=b >> 1;
		}
		return ans;
	}
	bool DFS(int index) {
		if (index == N) { return true; }
		int i,j;
		for (i = index; i < bmax; i++) {
			for (j = 0; j < vans.size(); j++) {
				if (map[vans[j]][i] < D) { break; }
			}
			if (j == vans.size())
			{
				vans.push_back(i);
				bool r = DFS(index + 1);
				if (r)return true;
				vans.pop_back();
			}
		}
		return false;
	}
public:
	void PROG() {
		cin >> N >> B >> D;
		bmax = 1;
		for (int i = 0; i < B; i++) {
			bmax = (bmax<<1);
		}

		for (int i = 0; i < bmax; i++) {
			for (int j = i + 1; j < bmax; j++) {
				map[i][j] = getDistance(i,j);
			}
		}

		vans.clear();

		DFS(0);

		for (int i = 0; i < N; i++) {
			cout << (int)vans[i];
			if ((i+1) % 10 == 0) { cout << endl; }
			else if(i== N - 1) { cout << endl; }
			else{ cout << " "; }
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