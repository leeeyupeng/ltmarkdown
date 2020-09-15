#include"leetcode.h"

#define NMAX 21
#define MAX 2502
class Solution {
private:
	vector<int> rods;
	int n;
	int maxheight;
	int halfmaxheight;
	int dp[NMAX][MAX * 4];
	int ans;
	int DP()
	{
		for (int i = 0; i <= maxheight; i++) {
			dp[0][i] = -INT_MAX;
		}
		dp[0][halfmaxheight] = 0;
		for (int i = 1; i <= n; i++) {
			for (int s = 0; s <= maxheight; s++) {
				dp[i][s] = dp[i - 1][s];
				if (s>=rods[i-1]) {
					dp[i][s] = max(dp[i][s], dp[i - 1][s - rods[i-1]] + rods[i-1]);
				}
				if (s + rods[i-1] <= maxheight) {
					dp[i][s] = max(dp[i][s], dp[i - 1][s + rods[i-1]]);
				}
			}
		}
		return dp[n][halfmaxheight];
	}
public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
		sort(this->rods.begin(),this->rods.end(),greater<int>());
		maxheight = 0;
		for (int i = n - 1; i >= 0; i--) {
			maxheight+=this->rods[i];
		}
		halfmaxheight = maxheight >> 1;
		ans = DP();
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//1,2
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}