
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
class Solution {
public:
	vector<vector<int>> matrix;
	int n;

	vector<int> distance;
	vector<int> prenode;
	vector<bool> visited;

	void Dijkstra(int start, int end)
	{
		int cur = start;

		int mindistance;
		int next;

		while (true)
		{
			for (int i = 0; i < n; i++)
			{
				if (visited[i] == false)
				{
					if (matrix[cur][i] != 0 && distance[i] > distance[cur] + matrix[cur][i])
					{
						distance[i] = distance[cur] + matrix[cur][i];
						prenode[i] = cur;
					}

					if (mindistance > distance[i])
					{
						mindistance = distance[i];
						next = i;
					}
				}
			}

			if (next == 0)
			{
				break;
			}
			visited[next] = true;
			cur = next;
			if (cur == end)
			{
				break;
			}
		}
	}
};