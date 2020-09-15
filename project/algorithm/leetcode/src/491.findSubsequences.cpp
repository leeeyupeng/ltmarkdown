#include"leetcode.h"

class Solution {
private:
	int n;
	vector<int> flag;
	vector<int> nums;
	vector<vector<int>> ans;
	vector<int> combine;
	void DFS(int index) {
		if (index == n) {
			if (combine.size() > 1) { ans.push_back(combine); }
			return;
		}
		if (combine.empty() || combine.back() <= nums[index]) {	
			if (flag[nums[index] + 100] != 0) {
				flag[nums[index] + 100] ++;
				DFS(index + 1);
				flag[nums[index] + 100] --;
			}
			else {
				combine.push_back(nums[index]);		
				vector<int> tempflag = flag;
				for (int i = nums[index] + 100 + 1; i < 202; i++) {
					flag[i] = 0;
				}
				DFS(index + 1);	
				flag = tempflag;
				combine.pop_back();
				flag[nums[index] + 100] ++;
				DFS(index + 1);
				flag[nums[index] + 100] --;
			}
		}
		else {
			flag[nums[index] + 100] ++;
			DFS(index + 1);
			flag[nums[index] + 100] --;
		}
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		this->nums= nums;
		n = this->nums.size();
		for (int i = 0; i < 202; i++) {
			flag.push_back(0);
		}
		DFS(0);
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	vector<int> nums = {
//4,6,7,7
//	};
//	vector<vector<int>> ans = s.findSubsequences(nums);
//	//cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}