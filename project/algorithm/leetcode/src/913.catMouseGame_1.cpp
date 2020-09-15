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
	int m[2][MAX][MAX];
	unordered_set<int> us;
	unordered_set<int> us2;
	int minimax(vector<vector<int>>& graph,int lastmouse,int lastcat,int mouse, int cat,bool mouseplay) {		
		if (m[mouseplay?0:1][mouse][cat] != 0) {
			return m[mouseplay ? 0 : 1][mouse][cat];
		}
		if (mouseplay) {
			if (us.find(lastmouse * MAX * MAX * MAX + lastcat * MAX * MAX + mouse * MAX + cat) != us.end()) {
				return m[mouseplay ? 0 : 1][mouse][cat];
			}
			us.insert(lastmouse * MAX * MAX * MAX + lastcat * MAX * MAX + mouse * MAX + cat);
		}
		else
		{
			if (us2.find(lastmouse * MAX * MAX * MAX + lastcat * MAX * MAX + mouse * MAX + cat) != us2.end()) {
				return m[mouseplay ? 0 : 1][mouse][cat];
			}
			us2.insert(lastmouse * MAX * MAX * MAX + lastcat * MAX * MAX + mouse * MAX + cat);
		}
		int res = 0;
		if (mouseplay) {
			res = -1;
			for (int i = 0; i < graph[mouse].size(); i++) {
				if (graph[mouse][i] == 0) { 
					res = max(res, 1); break; 
				}
				else if (graph[mouse][i] == cat) {
					res = max(res, -1); 
				}
				else {					
					res = max(res, -minimax(graph, mouse, lastcat,graph[mouse][i], cat, !mouseplay));
				}
			}
		}
		else {
			res = -1;
			int maxup = 1;
			for (int j = 0; j < graph[cat].size(); j++) {
				if (graph[cat][j] == 0) { continue; }
				else if (mouse == graph[cat][j]) { 
					res = max(res, 1); break; 
				}
				else 
				{ 					
					res = max(res, -minimax(graph, lastmouse, cat,mouse, graph[cat][j], !mouseplay));					
				}
			}		
		}
		m[mouseplay ? 0 : 1][mouse][cat] = res;
		return res;
	}
public:
	int catMouseGame(vector<vector<int>>& graph) {
		int n = graph.size();
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					m[k][i][j] = 0;
				}
			}
		}
		int ans = minimax(graph,0,0, 1, 2,true);
		if (ans == -1) { ans = 2; }
		return ans;
	} 
};

//int main()
//{
//	Solution s;
//	vector<vector<int>> graph = {
//		//{3,4 }, { 3,5 }, { 3,6 }, { 0,1,2 }, { 0,5,6 }, { 1,4 }, { 2,4 }
//		//{6 }, { 4 }, { 9 }, { 5 }, { 1,5 }, { 3,4,6 }, { 0,5,10 }, { 8,9,10 }, { 7 }, { 2,7 }, { 6,7 }
//		//{2,5 }, { 3 }, { 0,4,5 }, { 1,4,5 }, { 2,3 }, { 0,2,3 }
//		//{1,3 }, { 0 }, { 3 }, { 0,2 }
//		{6 }, { 4,11 }, { 9,12 }, { 5 }, { 1,5,11 }, { 3,4,6 }, { 0,5,10 }, { 8,9,10 }, { 7 }, { 2,7,12 }, { 6,7 }, { 1,4 }, { 2,9 }
//	};
//	int ans = s.catMouseGame(graph);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}