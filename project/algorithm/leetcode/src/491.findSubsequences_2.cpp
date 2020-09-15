#include"leetcode.h"

class Solution {
private:
	struct TrieNode {
		TrieNode* child[202];
		bool isFlag = false;
		TrieNode() {
			isFlag = false;
			memset(child,0,sizeof(TrieNode*)*202);
		}
	};

	TrieNode root;
	bool add(TrieNode* node,int index) {
		if (index == combine.size()) {
			bool isFlag = node->isFlag;
			node->isFlag = true;
			return isFlag;
		}
		int key = combine[index] + 100;

		if (node->child[key] == NULL) {
			node->child[key] = new TrieNode();
		}

		return add(node->child[key], index + 1);
	}
	int n;
	vector<int> nums;
	vector<vector<int>> ans;
	vector<int> combine;
	void DFS(int index) {
		if (index == n) {
			if (combine.size() > 1) {
				if (!add(&root, 0)) {
					ans.push_back(combine);
				}
			}
			return;
		}
		if (combine.empty() || combine.back() <= nums[index]) {
			combine.push_back(nums[index]);
			DFS(index + 1);
			combine.pop_back();
		}
		DFS(index + 1);
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		this->nums= nums;
		n = this->nums.size();
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