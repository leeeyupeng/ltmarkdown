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
	int dfs(vector<int>& nums,int i,int j,bool swap) {
		if (i == j) { return swap ? nums[i] :0; }
		int res = 0;
		if (swap) {
			res = dfs(nums, i + 1, j, !swap) + nums[i];
			res = max(res, dfs(nums, i, j - 1, !swap) + nums[j]);
		}
		else {
			res = dfs(nums, i + 1, j, !swap);
			res = min(res, dfs(nums, i, j - 1, !swap));
		}
		return res;
	}
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		int sums = 0;
		for (int i = 0; i < n; i++) {
			sums += nums[i];
		}
		int ans = dfs(nums,0,n-1,true);
		return ans + ans >= sums;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums = {
//2,5,3
//	};
//	bool ans = s.PredictTheWinner(nums);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}