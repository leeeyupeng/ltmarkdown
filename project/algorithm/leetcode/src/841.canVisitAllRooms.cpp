#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<int> visit;
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		visit = vector<int>(n);
		for (int i = 0; i < n; i++) {
			visit[i] = false;
		}
		queue<int> q;
		q.push(0);
		visit[0] = true;
		int count = 1;
		int room;
		while (!q.empty()) {
			room = q.front();
			q.pop();
			for (int i = 0; i < rooms[room].size(); i++)
			{
				if (visit[rooms[room][i]] == false) 
				{
					visit[rooms[room][i]] = true;
					q.push(rooms[room][i]);
					count++;

				}
			}
			if (count == n) { return count == n; }
		}
		return count == n;
	}
};