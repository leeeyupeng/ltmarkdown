/*
ID: leeyupeng
LANG: C++11
PROG: lamps
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG lamps
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

bool cmp(vector<bool>& a, vector<bool>& b) {
	for (int i = 1; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}
	return true;
}
class  Solution
{
private:
	int N;
	int C;
	vector<bool> vFlag;
	vector<bool> vONOFF;
	vector<bool> vCombine;
	vector<vector<bool>> vvans;
	void button(int combine) {
		
		if (combine & 0x1) {
			for (int i = 1; i <= N; i++) {
				vCombine[i] = !vCombine[i];
			}
		}
		if (combine & 0x2) {
			for (int i = 1; i <= N; i++,i++) {
				vCombine[i] = !vCombine[i];
			}
		}
		if (combine & 0x4) {
			for (int i = 2; i <= N; i++, i++) {
				vCombine[i] = !vCombine[i];
			}
		}
		if (combine & 0x8) {
			for (int k = 0; k <= N; k++) {
				int i = 3 * k + 1;
				if (i <= N) {
					vCombine[i] = !vCombine[i];
				}
				else{
					break;
				}
			}
		}
	}
	bool check(){
		for (int i = 1; i <= N; i++) {
			if (vFlag[i] == true) {
				if (vONOFF[i] != vCombine[i]) {
					return false;
				}
			}
		}
		return true;
	}
public:
	void PROG() {
		cin >> N >> C;
		int id = 0;
		vFlag.insert(vFlag.begin(),N +1,false);
		vONOFF.insert(vONOFF.begin(), N+1, false);
		vCombine.insert(vCombine.begin(), N +1, false);
		while (id != -1) {
			cin >> id;
			if (id != -1) { vFlag[id] = true; vONOFF[id] = true; }
		}
		id = 0;
		while (id != -1) {
			cin >> id;
			if (id != -1) { vFlag[id] = true; vONOFF[id] = false; }
		}

		for (int i = 0; i < (1 << 4); i++) {
			int count = 0;
			int ii = i;
			while (ii != 0) { count += (ii & 0x1); ii = (ii >> 1); }
			if (C >= count && (C & 0x1) == (count & 0x1)) {
				for (int j = 0; j <= N; j++) { vCombine[j] = true; }
				button(i);
				if (check()) {
					vvans.push_back(vCombine);
				}
			}
		}

		if (vvans.size() == 0) { cout << "IMPOSSIBLE" << endl; }
		sort(vvans.begin(), vvans.end(), cmp);
		for (int i = 0; i < vvans.size(); i++) {
			bool equip = false;
			if (i > 0) {
				equip = true;
				for (int j = N; j >=1; j--) {
					if (vvans[i][j] != vvans[i - 1][j]) {
						equip = false;
						break;
					}
				}
			}
			if (equip == false) {
				for (int j = 1; j <= N; j++) {
					cout << vvans[i][j] ? 1 : 0;
				}
				cout << endl;
			}
		}
	}
};

int main()
{
#ifdef FILESTREAM
	freopen(IN(PROG), "r", stdin);
	freopen(OUT(PROG), "w", stdout);
#endif
	Solution s;
	s.PROG();
#ifdef FILESTREAM
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}