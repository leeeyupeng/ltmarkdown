#include"leetcode.h"

#define MAX 2500
class Solution {
private:
	vector<int> rods;
	vector<int> rodssums;
	int n;
	int maxheight;
	int halfmaxheight;
	bool dp[MAX][MAX];
	int ans;
	int DP()
	{
		for (int i = halfmaxheight; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for (int k = 0; k < n; k++) {
			for (int i = halfmaxheight; i >= 0; i--) {
				for (int j = i; j >= 0; j--) {
					if (i - rods[k] >= 0) {
						if (i - rods[k] >= j) {
							dp[i][j] = dp[i][j] || dp[i - rods[k]][j];
						}
						else {
							dp[i][j] = dp[i][j] || dp[j][i - rods[k]];
						}
					}
					if (j - rods[k] >= 0) {
						dp[i][j] = dp[i][j] || dp[i][j - rods[k]];
					}
				}
			}
		}
		for (int i = halfmaxheight; i >= 0; i--) {
 			if (dp[i][i] == true) { ans = i; break; }
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