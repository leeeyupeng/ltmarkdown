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
using namespace std;

#define MAX 200
class Solution {
private:
	int m[MAX][MAX];
	unordered_set<int> us;
	int minimax(vector<vector<int>>& graph, int lastmouse, int lastcat,int mouse,int cat) {
		
		if (m[mouse][cat] != -1) {
			return m[mouse][cat];
		}
		int mouseres = 0x2,catres = 0x1;
		int cattemp;
		bool mouseflag = false;
		for (int i = 0; i < graph[mouse].size(); i++) {
			if (graph[mouse][i] == 0) { 
				mouseres = 0x1; mouseflag = true; break;
			}
			if (graph[mouse][i] == cat) { 
				mouseflag = true; 
				continue;
			}
			catres = 1;
			bool catflag = false;
			for (int j = 0; j < graph[cat].size(); j++) {
				if (graph[cat][j] == 0) { continue; }
				if (graph[mouse][i] == graph[cat][j]) { catres = 0x2; catflag = true; break; }
				if (us.find(mouse * MAX * MAX * MAX + cat * MAX * MAX + graph[mouse][i] * MAX + graph[cat][j]) != us.end())
				{
					continue;
				}
				else 
				{ 
					us.insert(mouse * MAX * MAX * MAX + cat * MAX * MAX + graph[mouse][i] * MAX + graph[cat][j]);
					cattemp = minimax(graph, mouse, cat, graph[mouse][i], graph[cat][j]); 
				}
				catres = ((catres & 0x2) | (cattemp & 0x2)) + ((catres & 0x1) & (cattemp & 0x1));
				catflag = true;
			}
			if (catflag) {
				mouseres = ((mouseres & 0x2) & (catres & 0x2)) + ((mouseres & 0x1) | (catres & 0x1));
				mouseflag = true;
			}
			else {
				//catres = 0x0;
				//mouseres = ((mouseres & 0x2) & (catres & 0x2)) + ((mouseres & 0x1) | (catres & 0x1));	
				//mouseres = 0;
				mouseres = (mouseres & 0x1);
				mouseflag = true;
				break;
			}
		}
		if (mouseflag) {
			m[mouse][cat] = ((mouseres & 0x1) == 0x1) ? 0x1 : mouseres;
		}
		else {
			//m[mouse][cat] = 0;
		}
		return m[mouse][cat];
	}
public:
	int catMouseGame(vector<vector<int>>& graph) {
		int n = graph.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				m[i][j] = -1;
			}
		}
		int ans = minimax(graph,0,0, 1, 2);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> graph = {
//		{3,4 }, { 3,5 }, { 3,6 }, { 0,1,2 }, { 0,5,6 }, { 1,4 }, { 2,4 }
//		//{6 }, { 4 }, { 9 }, { 5 }, { 1,5 }, { 3,4,6 }, { 0,5,10 }, { 8,9,10 }, { 7 }, { 2,7 }, { 6,7 }
//		//{2,5 }, { 3 }, { 0,4,5 }, { 1,4,5 }, { 2,3 }, { 0,2,3 }
//		//{1,3 }, { 0 }, { 3 }, { 0,2 }
//	};
//	int ans = s.catMouseGame(graph);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}