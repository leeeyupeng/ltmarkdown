/*
ID: leeyupeng
LANG: C++11
PROG: holstein
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define PROG holstein
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

class  Solution
{
private:
	int V;
	vector<int> vV;
	int G;
	vector<vector<int>> vvG;
	vector<int> BFS() {
		queue<vector<int>> q;
		q.push({});

		int i, j;
		while (!q.empty())
		{
			vector<int> v = q.front();
			q.pop();

			vector<int> vVitamin;
			vVitamin.insert(vVitamin.begin(), V,0);
			for (i = 0; i < v.size(); i++) {
				for (j = 0; j < V; j++) {
					vVitamin[j] += vvG[v[i]][j];
				}
			}

			for (i = 0; i < V; i++) {
				if (vVitamin[i] < vV[i]) { break; }
			}
			if (i == V) { return v; }
			int start = 0;
			if (!v.empty()) { 
				start = v[v.size() - 1] + 1;
			}
			for (int k = start; k < G; k++) {
				v.push_back(k);
				q.push(v);
				v.pop_back();
			}
		}

	}
public:
	void PROG() {
		cin >> V;
		vV.clear();
		vV.insert(vV.begin(),V,0);
		for (int i = 0; i < V; i++) {
			cin >> vV[i];
		}
		cin >> G;
		vvG.clear();
		vvG.insert(vvG.begin(), G, vector<int>(V));
		for (int i = 0; i < G; i++) {
			for (int j = 0; j < V; j++) {
				cin>>vvG[i][j];
			}
		}

		vector<int> vans = BFS();
		//sort(vans.begin(),vans.end());
		cout << vans.size()<<" ";
		for (int i = 0; i < vans.size(); i++) {
			cout << vans[i] + 1;
			if (i == vans.size() - 1) { cout << endl; }
			else { cout << " "; }
		}
	}
};

//int main()
//{
//#ifdef FILESTREAM
//	freopen(IN(PROG), "r", stdin);
//	freopen(OUT(PROG), "w", stdout);
//#endif
//	Solution s;
//	s.PROG();
//	return 0;
//}