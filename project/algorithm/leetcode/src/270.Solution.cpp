#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100005
class Solution {
	struct Node {
		vector<int> child;
		int parentnums = 0;
	};
private:
	Node nodes[MAX];
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			nodes[prerequisites[i][0]].parentnums++;
			nodes[prerequisites[i][1]].child.push_back(prerequisites[i][0]);
		}

		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (nodes[i].parentnums == 0) { q.push(i); }
		}

		int index = 0;
		int indexchild;
		int count = numCourses;
		while (count > 0) {
			if (q.empty()) { return false; }
			index = q.front();
			q.pop();
			for (int i = 0; i < nodes[index].child.size(); i++) {
				indexchild = nodes[index].child[i];
				nodes[indexchild].parentnums--;
				if (nodes[indexchild].parentnums == 0) {
					q.push(indexchild);
				}
			}
			nodes[index].child.clear();
			count--;
		}
		return true;
	}
};