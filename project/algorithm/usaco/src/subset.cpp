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
public:
	void PROG() {
		cin >> N;
		if ((N + 1)*N % 4 != 0) {
			cout << 0 << endl;
			return;
		}
		int sums = (N + 1) * N / 4;
		vector<vector<long long>> dp;
		dp.insert(dp.begin(), N +1, vector<long long>(sums + 1,0));
		for (int i = 0; i <= N; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= sums; j++) {
				dp[i][j] += dp[i - 1][j];
				if (j - i >= 0) {
					dp[i][j] += dp[i - 1][j - i];
				}
			}
		}
		cout << dp[N][sums] / 2 << endl;
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