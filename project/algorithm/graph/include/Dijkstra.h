#pragma once
#include "graph.h"

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

void dijkstra(vector<vector<int>>& graph,int start,vector<int>& dist){
	minheap<pair<int,int>> heap;
}

