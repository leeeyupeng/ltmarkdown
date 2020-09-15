#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
	struct qq {
		int index;
		double succProbSums;
		qq(int _index, double _succProbSums) :index(_index), succProbSums(_succProbSums) {}
		bool operator <(qq a) const { return succProbSums < a.succProbSums; }
	};
	struct graphnode {
		vector<int> edge;
	};
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		int en = edges.size();
		graphnode arrnodes[10001];
		for (int i = 0; i < en; i++) {
			arrnodes[edges[i][0]].edge.push_back(i);
			arrnodes[edges[i][1]].edge.push_back(i);
		}

		double v[10001];
		for (int i = 0; i < n; i++) { v[i] = 0; }
		bool vvisit[10001];
		for (int i = 0; i < n; i++) { vvisit[i] = false; }
		double ans = 0;
		int top;
		int edgeindex;
		double tempSuccProb;
		priority_queue<qq> pq;
		v[start] = 1;
		pq.push({start,1});
		int edgen;
		int edgenodeindex;
		while (!pq.empty()) {
			top = pq.top().index;
			pq.pop();
			if (vvisit[top]) { continue; }
			vvisit[top] = true;
			if (top == end) {
				ans = v[top]; break;
			}
			vector<int>& edge = arrnodes[top].edge;
			edgen = edge.size();
			for (int i = 0; i < edgen; i++) {
				edgeindex = edge[i];
				edgenodeindex = edges[edgeindex][0] == top ? edges[edgeindex][1] : edges[edgeindex][0];
				tempSuccProb = v[top] * succProb[edgeindex];
				
				if (vvisit[edgenodeindex] == false && v[edgenodeindex] < tempSuccProb) {
					v[edgenodeindex] = tempSuccProb;
					pq.push({ edgenodeindex,tempSuccProb });
				}
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> edges = {
//		{0,1 }, { 1,2 }, { 0,2 }
//	};
//	vector<double> succProb = {
//		0.5,0.5,0.2
//	};
//	int n = 3;
//	int start = 0;
//	int end = 2;
//	double ans = s.maxProbability(n,edges, succProb,start,end);
//	cout << ans<<endl;
//	system("PAUSE");
//
//	return 0;
//
//}