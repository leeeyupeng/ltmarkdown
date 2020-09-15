#include <iostream>
#include <vector>
#include "algorithm/algorithm.hpp"
using namespace std;
using namespace lt;
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		int left = 0, right = n-1;
		int leftHeight=0, rightHeight=0;
		while (left <= right) {			
			if (leftHeight <= rightHeight) {				
				ans += Max(0,leftHeight - height[left]);
				leftHeight = Max(leftHeight,height[left]);
				left++;
			}
			else {				
				ans += Max(0, rightHeight - height[right]);
				rightHeight = Max(rightHeight, height[right]);
				right--;
			}
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