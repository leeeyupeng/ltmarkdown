#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;

#define MAX 20
class Solution {
private:
	int dp[MAX][MAX];
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 0;
			}
		}
		int sums = 0;
		for (int i = 0; i < n; i++) {
			sums += nums[i];
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n - k; i++) {
				int j = i + k;
				if (i == j) { dp[i][j] = nums[i]; }
				else if (i + 1 == j) {
					dp[i][j] = nums[i] > nums[j] ? nums[i] : nums[j];
				}
				else {
					dp[i][j] = max(dp[i][j], min(dp[i + 2][j],dp[i+1][j-1]) + nums[i]);
					dp[i][j] = max(dp[i][j], min(dp[i][j-2], dp[i + 1][j - 1]) + nums[j]);
				}
			}
		}
		return dp[0][n - 1] + dp[0][n - 1] >= sums;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums = {
//2,4,55,6,8
//	};
//	bool ans = s.PredictTheWinner(nums);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}