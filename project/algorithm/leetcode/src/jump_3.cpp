#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		vector<int> before(n, INT32_MAX);
		before[0] = -1;
		int cur = 0;
		int end = 0;
		int i,j;
		for (i = 0; i < n; i++) {
			end = nums[i] + i;
			if (end > cur) {
				if (end > n - 1) {
					end = n - 1;
				}
				for (j = cur + 1; j <= end; j++) {
					before[j] = i;
				}
				cur = end;
				if (cur == n - 1) { break; }
			}
		}
		int ans = 0;
		int index = before[n - 1];
		while (index != -1) {
			ans++;
			index = before[index];
		}
		return ans;		
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//		2,3,1,1,4
//	};
//	int ans = s.jump(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}