/*
ID: leeyupeng
LANG: C++11
PROG: milk3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define PROG milk3
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	int ABC[3];
	//set<int> record;
	bool record[1024 * 32 + 2]{false};
	bool vans[21]{false};
	void DFS(int state) {
		if (record[state] == true) { return; }

		{
			int abc[3];
			abc[0] = (state >> 10) & 0x1F;
			abc[1] = (state >> 5) & 0x1F;
			abc[2] = state & 0x1F;

			if (abc[0] == 0) { 
				vans[abc[2]] = true;
			}
		}

		record[state] = true;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					int abc[3];
					abc[0] = (state >> 10) & 0x1F;
					abc[1] = (state >> 5) & 0x1F;
					abc[2] = (state & 0x1F);
					if (abc[i] == 0) { break; }
					if (abc[j] == ABC[j]) { continue; }

					if (abc[i] <= ABC[j] - abc[j]) {
						abc[j] += abc[i];
						abc[i] = 0;
					}
					else {
						abc[i] -= ABC[j] - abc[j];
						abc[j] = ABC[j];						
					}

					DFS((abc[0] << 10) + (abc[1] << 5) + abc[2]);
				}
			}
		}
	}
public:
	void PROG() {
		cin >> ABC[0] >> ABC[1] >> ABC[2];
		int initstate = 0;
		initstate = ABC[2];

		DFS(initstate);

		vector<int> v;
		for (int i = 0; i < 21; i++) {
			if (vans[i] == true) { v.push_back(i); }
		}
		for (int i = 0; i < v.size() - 1; i++) {
			cout << v[i]<<" ";
		}
		cout << v[v.size() - 1] << endl;
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