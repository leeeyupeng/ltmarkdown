#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>
using namespace std;
//https://leetcode-cn.com/problems/max-points-on-a-line/

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() <= 2)
		{
			return points.size();
		}
		vector<int> nums(points.size(), 0);

		{
			int i = 0;
			while (i < points.size())
			{
				nums[i] = 1;
				for (int j = points.size() - 1; j > i; j--)
				{
					if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
						points.erase(points.begin() + j);
						nums[i]++;
					}
				}
				i++;
			}
		}

		if (points.size() == 1)
		{
			return nums[0];
		}
		else if (points.size() == 2)
		{
			return nums[0] + nums[1];
		}

		int n = points.size();

		int maxnums = 0;

		for (int i = 0; i < n; i++)
		{
			maxnums += nums[i];
		}

		vector<vector<bool>> matrix(n);
		for (int i = 0; i < n; i++)
		{
			matrix[i].insert(matrix[i].begin(), points.size(), false);
			matrix[i][i] = true;
		}

		int ans = 2;

		int count;
		long long offsetx;
		long long offsety;
		long long offsetkx;
		long long offsetky;

		double p = 0.80;
		double p_inliers = double(ans) / double(maxnums);
		int N = ceil(log(1 - p) / log(1 - pow(p_inliers, 2)));
		int kk = 0;

		int temp;
		int i, j, k;
		srand((unsigned)time(NULL));
		while (kk++ < N)
		{

			i = rand() % n;
			j = rand() % n;

			if (matrix[i][j] == true || matrix[j][i] == true) { continue; }

			offsetx = points[j][0] - points[i][0];
			offsety = points[j][1] - points[i][1];

			count = 0;
			for (int k = 0; k < n; k++)
			{
				offsetkx = points[k][0] - points[i][0];
				offsetky = points[k][1] - points[i][1];
				if (offsetx * offsetky == offsetkx * offsety) {
					count += nums[k];
					matrix[i][k] = true; matrix[j][k] = true;
					matrix[k][i] = true; matrix[k][j] = true;
				}
			}
			if (count > ans)
			{
				ans = count;

				p_inliers = double(ans) / double(maxnums);
				N = ceil(log(1 - p) / log(1 - pow(p_inliers, 2)));
			}
		}
		return ans;
	}
};