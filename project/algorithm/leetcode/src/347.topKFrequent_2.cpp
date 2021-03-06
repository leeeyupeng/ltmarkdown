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
	struct Node {
		int value;
		int nums;
		Node(int _value, int _nums) :value(_value),nums(_nums){}
		bool operator < (const Node& rhs) const {
			if (nums == rhs.nums) {
				return value < rhs.value;
			}
			return  nums > rhs.nums;
		}
	};
	vector<Node> vNode;
	unordered_map<int, int> m;

	void select(int s,int e,int k) {
		int i = s, j = e;

		Node selectNode = vNode[e];
		while (i < j) {
			while (i < j)
			{
				if (vNode[i].nums < selectNode.nums) {
					vNode[j] = vNode[i];
					break;
				}
				else
				{
					i++;
				}
			}
			while (i < j)
			{
				if (vNode[j].nums >= selectNode.nums) {
					vNode[i] = vNode[j];
					break;
				}
				else
				{
					j--;
				}
			}
		}

		vNode[i] = selectNode;
		if (i == k) {}
		else if (i < k) { select(i+1,e,k); }
		else { select(s, i-1, k); }
	}
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (m.find(nums[i]) == m.end()) {
				vNode.push_back({ nums[i],0 });
				m[nums[i]] = vNode.size()-1;
			}
			vNode[m[nums[i]]].nums++;
		}
		select(0,vNode.size()-1,k-1);
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(vNode[i].value);
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums{
//3,0,1,0
//	};
//	int k = 1;
//	vector<int> ans = s.topKFrequent(nums,k);
//	system("PAUSE");
//	return 0;
//}