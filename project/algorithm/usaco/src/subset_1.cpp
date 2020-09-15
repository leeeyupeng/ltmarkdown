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

// DFS ³¬Ê±
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
	vector<int> vSum;
	void DFS(int sum,int index) {
		if (index > N) { return; }
		if (sum > sums) { return; }
		if (sum == sums) { ans++; return; }
		if (sum + index > sums) { return; }
		if (sum + vSum[index] < sums) { return; }

		for (int i = index; i <= N; i++) {
			sum += i;
			DFS(sum,i+1);
			sum -= i;
		}
	}
public:
	void PROG() {
		cin >> N;
		if ((N + 1)*N % 4 != 0) {
			cout << 0 << endl;
			return;
		}
		sums = (N + 1) * N / 4;
		vSum.insert(vSum.begin(),N+1,0);
		vSum[N] = N;
		for (int i = N-1; i > 0; i--) {
			vSum[i] = vSum[i + 1] + i;
		}
		ans = 0;
		DFS(0,1);
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