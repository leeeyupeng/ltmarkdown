#include"leetcode.h"

#define MAX 5000
class Solution {
private:
	vector<int> rods;
	vector<int> rodssums;
	int n;
	int maxheight;
	int halfmaxheight;
	bool dp[MAX];
	int ans;
	int DP()
	{
		for (int i = 0; i <= maxheight; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for (int k = 0; k < n; k++) {
			for (int i = maxheight; i > 0; i--) {
				if (i - rods[k] >= 0) {
					dp[i] = dp[i] || dp[i - rods[k]];
				}
			}
		}
		int height = 0;
		for (int i = 0; i < maxheight; i++) {
			if (((maxheight - i) & 0x1) == 0x0) {
				height = (maxheight - i) >> 1;
				if (dp[i] == true && dp[height + i] == true && dp[maxheight] == true) {
					ans = height;
					break;
				}
			}
		}
		return ans;
	}
public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
		rodssums = vector<int>(n + 1, 0);
		rodssums[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			rodssums[i] = rodssums[i + 1] + this->rods[i];
		}
		maxheight = rodssums[0];
		halfmaxheight = maxheight >> 1;

		ans = 0;
 		ans = DP();

		return ans;
	}
};

//int main()
//{
//	Solution s; 
//	vector<int> matrix{
//33,30,41,34,37,29,26,31,42,33,38,27,33,31,35,900,900,900,900
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}