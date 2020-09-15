#include"leetcode.h"

class Solution {
private:
	int n;
	bool flag[16];
	vector<int> nums;
	vector<vector<int>> ans;
	vector<int> combine;
	void DFS(int index) {
		if (index == n) {
			if (combine.size() > 1) { ans.push_back(combine); }
			return;
		}
		if (combine.empty() || combine.back() <= nums[index]) {
			bool fflag = true;
			int i = index - 1;
			while (i >= 0)
			{
				if (flag[i] == true && nums[i] < nums[index]) { break; }
				if (flag[i] == false && nums[i] == nums[index]) { fflag = false; break; }
				i--;
			}
			if (fflag) {
				combine.push_back(nums[index]);
				flag[index] = true;
				DFS(index + 1);
				flag[index] = false;
				combine.pop_back();
			}			
		}
		DFS(index + 1);
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		this->nums= nums;
		n = this->nums.size();
		for (int i = 0; i < 16; i++) {
			flag[i] = false;
		}
		DFS(0);
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	vector<int> nums = {
//1,2,1,2,1,2
//	};
//	vector<vector<int>> ans = s.findSubsequences(nums);
//	//cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}