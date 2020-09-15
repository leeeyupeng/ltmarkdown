#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

#define MAX 505
class Solution {
private:
	bool dp[MAX];
	vector<pair<int, int>> path[MAX];
	vector<int> vsums;
	vector<vector<int>> ans;
	void dfs(vector<int>& candidates,int target, int index,vector<int>& vsums) {
		if (target == 0) { ans.push_back(vsums); }
		for (int i = 0; i < path[target].size(); i++) {
			if (path[target][i].second <= index) {
				vsums.push_back(candidates[path[target][i].second]);
				dfs(candidates, path[target][i].first, path[target][i].second, vsums);
				vsums.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int n = candidates.size();
		sort(candidates.begin(),candidates.end());
		for (int i = 1; i <= target; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for (int i = 0; i < n; i++) {
			for (int t = candidates[i]; t <= target; t++) {				
				if (dp[t - candidates[i]] == true) {
					path[t].push_back({ t - candidates[i],i});
				}
				dp[t] = dp[t] || dp[t - candidates[i]];
			}
		}
		dfs(candidates,target,n-1,vsums);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums{
//2,3,5,6,4,1
//	};
//	int k = 8;
//	vector<vector<int>> ans = s.combinationSum(nums,k);
//	system("PAUSE");
//	return 0;
//}