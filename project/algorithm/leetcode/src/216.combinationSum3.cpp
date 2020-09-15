#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
private:
	int n, k;
	vector<int> path;
	vector<vector<int>> ans;
	void dfs(int index,int nums, int count) {
		if (count == k) {
			if (nums == n) {
				ans.push_back(path);
			}
			return;
		}
		if (nums + index > n) { return; }
		if (count + 1 <= k) {
			path.push_back(index);
			dfs(index + 1, nums + index, count + 1);
			path.pop_back();
		}
		if (count + 10 - index - 1 >= k) {
			dfs(index + 1, nums, count);
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		this->n = n;
		this->k = k;
		dfs(1, 0, 0);
		return ans;
	}
};