#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#include "tree/MinHeap_2.h"
#include "tree/BITree_1.h"
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
				minheap.Pop();
			}

			while (i < n && buildings[i][0] == curx) {
				bitree.add(buildings[i][1]-1,buildings[i][2]);
				minheap.Push(i);
				i++;
			}
			curheight = bitree.getMax(curx);
			if (lastheight != curheight) {
				ans.push_back({ curx,curheight });
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
//		//		{2, 9 ,10 }, { 3, 7 ,15 }, { 5 ,12 ,12 }, { 15, 20 ,10 }, { 19, 24 ,8 }
//		//		{2,4,7},{2,4,5},{2,8,6}
//		//{0,2147483647,2147483647}
//		{6765,184288,53874},{13769,607194,451649},{43325,568099,982005},{47356,933141,123943},{59810,561434,119381},{75382,594625,738524},{111895,617442,587304},{143767,869128,471633},{195676,285251,107127},{218793,772827,229219},{316837,802148,899966},{329669,790525,416754},{364886,882642,535852},{368825,651379,6209},{382318,992082,300642},{397203,478094,436894},{436174,442141,612149},{502967,704582,918199},{503084,561197,625737},{533311,958802,705998},{565945,674881,149834},{615397,704261,746064},{624917,909316,831007},{788731,924868,633726},{791965,912123,438310}
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