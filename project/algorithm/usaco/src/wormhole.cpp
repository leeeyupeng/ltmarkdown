/*
ID: leeyupeng
LANG: C++11
PROG: wormhole
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG wormhole
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

class  Solution
{
public:
	int n;
	int ans;
	vector<vector<int>> vn;
	vector<vector<int>> vvc;
	vector<int> vc;
	vector<int> vnext;
	vector<int> vpair;
	void combine(int index) { 		
		if (n == index) {
			vvc.push_back(vc);
			return;
		}
		if (index % 2 == 0) {
			for (int i = index; i < n; i++) {
				if (index - 2 < 0 || vc[i] > vc[index - 2]) {
					swap(vc[index], vc[i]);
					combine(index + 1);
					swap(vc[index], vc[i]);
				}
			}
		}
		else {
			for (int i = index; i < n; i++) {
				if (vc[i] > vc[index - 1]) {
					swap(vc[index], vc[i]);
					combine(index + 1);
					swap(vc[index], vc[i]);
				}
			}
		}
	}

	bool Check(){
		int pos;
		for (int i = 0; i < n; i++) {
			pos = i;
			for (int j = 0; j < n; j++)
			{
				pos = vnext[vpair[pos]];
				if (pos == -1) { break; }
			}
			if (pos != -1) return true;
		}
		return false;
	}

	void PROG() {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vn.push_back({x, y});
		}

		vvc.clear();
		vc.clear();
		for (int i = 0; i < n; i++) {
			vc.push_back(i);
		}
		combine(0);
		vnext.clear();
		for (int i = 0; i < n; i++) {
			vnext.push_back(-1);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vn[i][1] == vn[j][1] && vn[i][0] < vn[j][0]) {
					if (vnext[i] == -1 ||vn[j][0] - vn[i][0] < vn[vnext[i]][0] - vn[i][0]) {
						vnext[i] = j;
					}
				}
			}
		}

		vpair.clear();
		for (int i = 0; i < n; i++) {
			vpair.push_back(0);
		}

		ans = 0;
		for (int i = 0; i < vvc.size(); i++) {
			vc = vvc[i];
			for (int j = 0; j < n; j++, j++) {
				vpair[vc[j]] = vc[j + 1];
				vpair[vc[j+1]] = vc[j];
			}
			if (Check()) { ans++; }
		}

		cout << ans << endl;
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