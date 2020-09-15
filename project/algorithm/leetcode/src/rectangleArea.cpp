#include"leetcode.h"
#define XYNUMSMAX 200
class Solution {
private:
	int arrx[XYNUMSMAX * 2];	
	int arry[XYNUMSMAX * 2];
	int matrix[XYNUMSMAX * 2][XYNUMSMAX * 2];

	unordered_map<int, int> mapx;
	unordered_map<int, int> mapy;
	inline void insertsort(unordered_map<int, int>& map,int* arr, int element) {
		if (map.find(element) != map.end()) { return; }
		int nums = map.size();
		int i = nums;
		while (i > 0) {
			if (arr[i-1] > element) { arr[i] = arr[i-1]; map[arr[i]] = i; i--; }
			else { break; }
		}
		arr[i] = element;
		map[arr[i]] = i;
	}
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		int n = rectangles.size();		
		for (int i = 0; i < n; i++) {
			vector<int>& rectangle = rectangles[i];
			insertsort(mapx,arrx, rectangle[0]);
			insertsort(mapx,arrx, rectangle[2]);
			insertsort(mapy,arry, rectangle[1]);
			insertsort(mapy,arry, rectangle[3]);
		}
		for (int i = 0; i < mapx.size(); i++) {
			for (int j = 0; j < mapy.size(); j++) {
				matrix[i][j] = 0;
			}
		}
		int x1, x2, y1, y2;
		for (int i = 0; i < n; i++) {
			vector<int>& rectangle = rectangles[i];
			x1 = mapx[rectangle[0]];
			y1 = mapy[rectangle[1]];
			x2 = mapx[rectangle[2]];
			y2 = mapy[rectangle[3]];

			for (int xx = x1+1; xx <= x2; xx++) {
				for (int yy = y1+1; yy <= y2; yy++) {
					matrix[xx][yy] = i + 1;
				}
			}
		}

		long long ans = 0;
		for (int i = 1; i < mapx.size(); i++) {
			for (int j = 1; j < mapy.size(); j++) {
				if (matrix[i][j] != 0) {
					ans += (long long)(arrx[i] - arrx[i - 1]) * (long long)(arry[j] - arry[j - 1]);
					ans %= 1000000007;
				}
			}
		}
		return ans;
	}
};

//#include <algorithm>
//#include <functional>
//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
//		{49,40,62,100 }, { 11,83,31,99 }, { 19,39,30,99 }
//	};
//	using std::placeholders::_1;
//	auto rectangleArea = std::bind(&Solution::rectangleArea, &s, _1);
//	int ans = rectangleArea(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}
