#include"leetcode.h"

#define MAX 2502
class Solution {
private:
	vector<int> rods;
	int n;
	int maxheight;
	int halfmaxheight;
	int dp1[MAX];
	int dp2[MAX];
	int ans;
	int DP()
	{
		for (int i = 0; i <= halfmaxheight; i++) {
			dp1[i] = -1;
		}
		dp1[0] = 0;
		int* dp = dp1;
		int* dpnext = dp2;
		int *temp;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i <= halfmaxheight; i++) {
				dpnext[i] = dp[i];
				if (i + rods[k] <= halfmaxheight && dp[i + rods[k]] >= 0) {
					dpnext[i] = max(dpnext[i],dp[i + rods[k]] + rods[k]);
				}
				if (i - rods[k] >= 0 && dp[i - rods[k]]>=0) {
					dpnext[i] = max(dpnext[i], dp[i - rods[k]] + rods[k]);
				}
				else if (rods[k] - i >= 0 && rods[k] - i  <= halfmaxheight && dp[rods[k] - i] >= 0){
					dpnext[i] = max(dpnext[i], dp[rods[k] - i] + rods[k]);
				}
			}
			temp = dp;
			dp = dpnext;
			dpnext = temp;
		}
		return dp[0]>>1;
	}
public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
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
//100
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}