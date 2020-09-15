#include"leetcode.h"
using namespace std;

#include "tree/MinHeap_2.h"

using namespace lt::tree;
class Solution {
private:
	bool cmp(vector<vector<int>>& courses, const int& a, const int& b) {
		return courses[a][1] < courses[b][1];
	}
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		int n = courses.size();
		int* arr = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}

		using std::placeholders::_1;
		using std::placeholders::_2;
		auto bound_cmp = std::bind(&Solution::cmp, this, courses, _1, _2);
		MinHeap<int> minheap(n + 1,arr,n, bound_cmp);

		int ans = 0;
		int index = 0;
		int startday = 0;
		int nowday = 0;
		while (!minheap.Empty()) {
			index = minheap.Top();
			minheap.Pop();
			startday = courses[index][1] - courses[index][0];
			if (nowday <= startday) {
				ans++;
				nowday += courses[index][0];
			}
			else {
				//break;
			}
		}
		free(arr);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
//		{100,100 }, {100,200}
//	};
//	int ans = s.scheduleCourse(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}