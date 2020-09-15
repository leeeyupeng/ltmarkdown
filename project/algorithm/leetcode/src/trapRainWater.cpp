#include"leetcode.h"
#include "algorithm/algorithm.hpp"
using namespace lt;
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int n = heightMap.size();
		if (n < 3) { return 0; }
		int m = heightMap[0].size();
		if (m < 3) { return 0; }
		vector<vector<int>> left2right = heightMap;
		for (int j = 1; j < m - 1; j++) {
			for (int i = 1; i < n-1; i++) {
				left2right[i][j] = Max(left2right[i][j], left2right[i][j-1]);
			}
		}

		vector<vector<int>> right2left = heightMap;
		for (int j = m - 2; j > 0; j--) {
			for (int i = 1; i < n-1; i++) {
				right2left[i][j] = Max(right2left[i][j], right2left[i][j+1]);
			}
		}

		vector<vector<int>> up2bot = heightMap;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m-1; j++) {
				up2bot[i][j] = Max(up2bot[i][j], up2bot[i-1][j]);
			}
		}
		vector<vector<int>> bot2up = heightMap;
		for (int i = n-2; i > 0; i--) {
			for (int j = 1; j < m - 1; j++) {
				bot2up[i][j] = Max(bot2up[i][j], bot2up[i + 1][j]);
			}
		}
		vector<vector<int>> height = heightMap;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				height[i][j] = Min(left2right[i][j - 1], right2left[i][j + 1], up2bot[i - 1][j], bot2up[i + 1][j]);
				height[i][j] = Max(height[i][j],heightMap[i][j]);
			}
		}
		int kk = 1;
		bool flag = true;
		while(flag == true){	
			flag = false;
			for (int i = 1; i < n - 1;i ++) {
				for (int j = 1; j < m - 1; j ++) {
					int last = height[i][j];
					height[i][j] = Min(height[i][j - 1], height[i][j + 1], height[i - 1][j], height[i + 1][j]);
					height[i][j] = Max(height[i][j], heightMap[i][j]);
					if (height[i][j] < last) { flag = true; }
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				ans += Max(0, height[i][j] - heightMap[i][j]);
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
//		{12,13,1,12 }, 
//		{13,4,13,12 }, 
//		{13,8,10,12 }, 
//		{12,13,10,10 }, 
//		{13,13,13,13 }
//	};
//	int ans = s.trapRainWater(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}