/*
ID: leeyupeng
LANG: C++11
PROG: combo
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG combo
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

class  Solution
{
public:
	int vfarmer[3];
	int vmaster[3];
	int vs[3];
	int ans;
	int n;

	bool Is(int v1[3], int v2[3]) {
		for (int i = 0; i < 3; i++) {
			if (abs(v2[i] - v1[i]) >= 3
				&& abs(n - v2[i] + v1[i]) >= 3
				&& abs(n - v1[i] + v2[i]) >= 3) {
				return false;
			}
		}
		return true;
	}
	void Search(int vs[3], int index) {
		if (index == 3) {
			if (Is(vfarmer, vs)) { ans++; }
			else if (Is(vmaster, vs)) { ans++; }
			return;
		}

		for (int i = 1; i <= n; i++) {
			vs[index] = i;
			Search(vs, index + 1);
		}
	}
	void PROG() {
		cin >> n;
		for (int i = 0; i < 3; i++) { cin >> vfarmer[i]; }
		for (int i = 0; i < 3; i++) { cin >> vmaster[i]; }
		ans = 0;

		Search(vs, 0);

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