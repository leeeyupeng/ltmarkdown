#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

#include "Astar.h"

using namespace std;
//https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

//AStar×î¶ÌÂ·
int shortestPath(vector<vector<int>>& grid, int k) 
{
	int m = grid.size();
	int n = 0;
	if (m > 0)
	{
		n = grid[0].size();
	}

	Astar astar;
	astar.InitAstar(grid);
	Point start = Point(0, 0);
	Point target = Point(m - 1, n - 1);
	std::list<Point *> listPoint = astar.GetPath(start, target,true);

	return listPoint.size();
}