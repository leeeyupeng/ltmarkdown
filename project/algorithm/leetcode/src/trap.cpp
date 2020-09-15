#include <iostream>
#include <vector>
#include "algorithm/algorithm.hpp"
#include "datastructure/stack.hpp"
using namespace std;
using namespace lt;
class Solution {
public:
	int trap(vector<int>& height) {
		Stack<int> s;
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			while (!s.Empty() && height[s.Top()] <= height[i]) {
				int top = s.Top();
				s.Pop();
				if (!s.Empty()) {
					ans += (i - s.Top() - 1) * (Min(height[i], height[s.Top()]) - height[top]);
				}
			}
			s.Push(i);
		}

		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//		0,1,0,2,1,0,1,3,2,1,2,1
//	};
//	int ans = s.trap(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}