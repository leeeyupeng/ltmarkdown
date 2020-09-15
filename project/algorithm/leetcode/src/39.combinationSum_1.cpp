#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
private:
	int n;
	vector<vector<int>> ans;
	void dfs(vector<int>& candidates, int target,int index,int sums, vector<int>& path) {
		if (target == sums) { ans.push_back(path); return; }
		if (index >= n) { return; }
		if (candidates[index] > target - sums) { return; }
		int indexsums = 0;
		while (sums + indexsums + candidates[index] <= target) {
			indexsums += candidates[index];
			path.push_back(candidates[index]);	
			dfs(candidates, target, index + 1, sums + indexsums, path);
		}
		while (indexsums > 0) {
			indexsums -= candidates[index];
			path.pop_back();
		}
		dfs(candidates, target, index + 1, sums + indexsums, path);
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		n = candidates.size();
		sort(candidates.begin(),candidates.end());
		//reverse(candidates.begin(), candidates.end());
		vector<int> path;
		dfs(candidates, target, 0, 0, path);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums{
//2,3,6,7
//	};
//	int k = 7;
//	vector<vector<int>> ans = s.combinationSum(nums,k);
//	system("PAUSE");
//	return 0;
//}