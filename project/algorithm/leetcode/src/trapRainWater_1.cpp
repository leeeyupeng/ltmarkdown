#include <iostream>
#include <vector>
using namespace std;

#include "tree/MinHeap.h"
using namespace tree;


#define MAXHEIGHT 20000
class Solution {
private:
	template<class T>
	inline T Max(T a, T b) {
		return a >= b ? a : b;
	}

	struct Grid {
		int x;
		int y;
		int height;
		Grid(int _x, int _y, int _height) :x(_x), y(_y), height(_height) {}
		bool operator <(Grid& other) const
		{
			return height < other.height;
		}
		bool operator >(Grid& other) const
		{
			return height > other.height;
		}
	};
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int n = heightMap.size();
		if (n < 3) { return 0; }
		int m = heightMap[0].size();
		if (m < 3) { return 0; }
		vector<vector<int>> maxHeightMap = heightMap;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				maxHeightMap[i][j] = MAXHEIGHT;
			}
		}

		Grid * edges = (Grid*)malloc(sizeof(Grid) * (2 * n + 2* m - 4));
		int index = 0;
		for (int i = 0; i < n; i++) {
			edges[index++] = Grid(i,0,heightMap[i][0]);
			edges[index++] = Grid(i, m-1, heightMap[i][m-1]);
		}
		for (int j = 1; j < m - 1; j++) {
			edges[index++] = Grid(0, j, heightMap[0][j]);
			edges[index++] = Grid(n-1, j, heightMap[n-1][j]);
		}

		MinHeap<Grid> minheap((int)(((2 * n + 2 * m - 4) + RESIZE) / RESIZE) * RESIZE,edges, (2 * n + 2 * m - 4));

		while (!minheap.Empty()) {
			Grid grid = minheap.Top();
			minheap.Pop();

			//左格子
			int maxHeight;
			if (grid.x > 1) {
				maxHeight = Max(grid.height, heightMap[grid.x - 1][grid.y]);
				if (maxHeight < maxHeightMap[grid.x - 1][grid.y]) {
					maxHeightMap[grid.x - 1][grid.y] = maxHeight;
					minheap.Push(Grid(grid.x - 1,grid.y, maxHeight));
				}
			}
			//右格子
			if (grid.x < n-1) {
				maxHeight = Max(grid.height, heightMap[grid.x + 1][grid.y]);
				if (maxHeight < maxHeightMap[grid.x + 1][grid.y]) {
					maxHeightMap[grid.x + 1][grid.y] = maxHeight;
					minheap.Push(Grid(grid.x + 1, grid.y, maxHeight));
				}
			}
			//上格子
			if (grid.y > 1) {
				maxHeight = Max(grid.height, heightMap[grid.x][grid.y - 1]);
				if (maxHeight < maxHeightMap[grid.x][grid.y - 1]) {
					maxHeightMap[grid.x][grid.y - 1] = maxHeight;
					minheap.Push(Grid(grid.x , grid.y - 1, maxHeight));
				}
			}
			//下格子
			if (grid.y < m-1) {
				maxHeight = Max(grid.height, heightMap[grid.x][grid.y + 1]);
				if (maxHeight < maxHeightMap[grid.x][grid.y + 1]) {
					maxHeightMap[grid.x][grid.y + 1] = maxHeight;
					minheap.Push(Grid(grid.x, grid.y + 1, maxHeight));
				}
			}
		}

		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				ans += Max(0, maxHeightMap[i][j] - heightMap[i][j]);
			}
		}
		return ans;
	}
};

//#include<queue>
//int main()
//{
//	Solution s;
//	vector<vector<int>> matrix{
//	};
//	int ans = s.trapRainWater(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}