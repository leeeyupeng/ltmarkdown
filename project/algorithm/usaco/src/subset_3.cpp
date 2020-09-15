/*
ID: leeyupeng
LANG: C++11
PROG: subset
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// ÕÛ°ëËÑË÷

using namespace std;
#define PROG subset
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	int N;
	int sums;
	long long ans;
	map<int, int> mapSum;
	void DFS(int sum,int index) {
		if (sum > sums) { return; }
		if (index > N / 2) {
			mapSum[sum]++;
			return;
		}
		DFS(sum, index + 1);
		DFS(sum + index, index + 1);
	}
	void DFS2(int sum, int index) {
		if (sum > sums) { return; }
		if (index > N) {	
			ans += mapSum[sums - sum];
			return;
		}

		DFS2(sum, index + 1);
		DFS2(sum + index, index + 1);
	}
public:
	void PROG() {
		cin >> N;
		if ((N + 1)*N % 4 != 0) {
			cout << 0 << endl;
			return;
		}
		sums = (N + 1) * N / 4;
		ans = 0;
		for (int i = 1; i <= sums; i++) {
			mapSum.insert({i,0});
		}
		DFS(0,1);

		DFS2(0, N / 2 + 1);
		cout << ans / 2 << endl;
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
//#ifdef FILESTREAM
//fclose(stdin);
//fclose(stdout);
//#endif
//	return 0;
//}