#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#include "tree/MinHeap_2.h"
#include "tree/BITree.h"
using namespace lt::tree;

//https://leetcode-cn.com/problems/the-skyline-problem/

class Solution {
private:
	bool cmp(const int& a, const int& b) {
		if (m_buildings[a][1] == m_buildings[b][1]) {
			return a < b;
		}
		return m_buildings[a][1] < m_buildings[b][1];
	}
	vector<vector<int>> m_buildings;
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		m_buildings = buildings;
		int n = buildings.size();
		vector<vector<int>> ans;
		BITree bitree;
		using std::placeholders::_1;
		using std::placeholders::_2;
		auto bound_cmp = std::bind(&Solution::cmp, this, _1, _2);

		MinHeap<int> minheap(bound_cmp);
		bitree.init(n);
		int lastheight = 0;
		int curheight = 0;
		int offset = 0;
		int curx;
		int i = 0;
		int top = 0;
		while (i < n || !minheap.Empty()) {
			lastheight = curheight;
			curx = INT_MAX;
			if (i < n) { curx = min(curx, buildings[i][0]); }
			if (!minheap.Empty()) { curx = min(curx, buildings[minheap.Top()][1]); }
			while (!minheap.Empty() && buildings[minheap.Top()][1] == curx) {
				top = minheap.Top();
				minheap.Pop();
				bitree.updateBITree(top, -buildings[top][2]);
				if (!minheap.Empty()) {
					offset = min(0, offset + min(buildings[top][2], curheight));
				}
				curheight = bitree.getSum(i - 1) + offset;
			}

			while (i < n && buildings[i][0] == curx) {
				bitree.updateBITree(i, buildings[i][2]- min(curheight, buildings[i][2]));
				if (i > 0) {
					offset = min(0, offset - min(curheight, buildings[i][2]));
				}
				minheap.Push(i);
				i++;
				curheight = bitree.getSum(i - 1) + offset;
			}
			curheight = bitree.getSum(i-1) + offset;
			if (lastheight != curheight) {
				ans.push_back({curx,curheight});
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
////		{2, 9 ,10 }, { 3, 7 ,15 }, { 5 ,12 ,12 }, { 15, 20 ,10 }, { 19, 24 ,8 }
//		{2,4,7},{2,4,5},{2,8,6}
//	};
//	using std::placeholders::_1;
//	auto getSkyline = std::bind(&Solution::getSkyline, &s, _1);
//	vector<vector<int>> ans = getSkyline(matrix);
//	//cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}