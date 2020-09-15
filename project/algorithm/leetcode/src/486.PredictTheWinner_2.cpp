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
	int n;
	int m[MAX*MAX * 2];
	int dfs(vector<int>& nums,int i,int j,bool swap) {
		if (m[((i*n + j) << 1) + swap] != 0) {
			return m[((i*n + j) << 1) + swap];
		}
		int res = 0;
		if (i == j) {
			res = swap ? nums[i] : 0;
		}
		else if (swap) {
			res = dfs(nums, i + 1, j, !swap) + nums[i];
			res = max(res, dfs(nums, i, j - 1, !swap) + nums[j]);			
		}
		else {
			res = dfs(nums, i + 1, j, !swap);
			res = min(res, dfs(nums, i, j - 1, !swap));
		}
		m[((i*n + j) << 1) + swap] = res;
		return res;
	}
public:
	bool PredictTheWinner(vector<int>& nums) {
		n = nums.size();
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
//2,5,3,4,6,5,46,4896,46,48,465,48,465,48,46,48,46,48,46,49,46,46,4186,1468,6
//	};
//	bool ans = s.PredictTheWinner(nums);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}