#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
private:
	int n, k;
	int graph[11][11];
	void makegraphdfs(int node,int count) {
		if (n == count) { return; }
		for (int i = 0; i < k; i++) {
			graph[node][i]++;
			makegraphdfs(i, count +1);
		}
	}
	void makegraph() {
		for (int i = 0; i < k; i++) {
			makegraphdfs(i, 1);
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				graph[i][j] = ((pow(k,n) * (n - 1) / (n-1)) / k) / (k-1);
			}
			//graph[i][i] = n - 1;
		}
	}

	vector<int> vans;
	// Hierholzer Ëã·¨
	void dfs(int node) {
		for (int j = 0; j < k; j++) {
			if (graph[node][j] > 0) {
				--graph[node][j];
				dfs(j);
			}
		}
		vans.push_back(node);
	}
public:
	string crackSafe(int n, int k) {
		this->n = n;
		this->k = k;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++) {
				graph[i][j] = 0;
			}
		}
		makegraph();
		//for (int i = k-1; i >=0; i--)
		//{
		//	dfs(i);
		//}
		dfs(k-1);
		string ans;
		for (int i = 0; i < vans.size(); i++) {
			ans.push_back(vans[i] + '0');
		}
 		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string ans = s.crackSafe(2,3);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}