#include"leetcode.h"
class Solution {
public:
	bool winnerSquareGame(int n) {
		vector<bool> dp(n + 1,false);
		dp[0] = false;
		dp[1] = true;
		int i, j;
		int nn;
		for (i = 0; i <= n; i++) {
			if (dp[i] == false) {
				nn = sqrt(n - i);
				for (j = 1; j <= nn; j++) {
					dp[i + j * j] = true;
				}
				if (dp[n]) { return dp[n]; }
			}
		}
		return dp[n];
	}
};

//int main()
//{
//	Solution s;
//	bool ans = s.winnerSquareGame(100002);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}