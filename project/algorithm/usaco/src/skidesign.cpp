/*
ID: leeyupeng
LANG: C++11
PROG: skidesign
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG skidesign
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	int n;
	vector<int> vn;
	vector<int> vcostup;
	vector<int> vcostdown;
	int ans = INT32_MAX;
public:
	void PROG() {
		cin >> n;
		vn.clear();
		vn.insert(vn.begin(),n,0);
		for (int i = 0; i < n; i++) {
			cin >> vn[i];
		}

		vcostup.clear();
		vcostup.insert(vcostup.begin(), 101, 0);
		vcostdown.clear();
		vcostdown.insert(vcostdown.begin(), 101, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 17; j <= 100; j++)
			{
				if (vn[i] > j) { vcostup[j] += (vn[i] - j) * (vn[i] - j); }
			}

			for (int j = 0; j <= 100 - 17; j++)
			{
				if (vn[i] < j) { vcostdown[j] += (j - vn[i]) * (j - vn[i]); }
			}
		}
		ans = INT32_MAX;
		for (int i = 0; i <= 100 - 17; i++) {
			int cost = 0;
			cost = vcostdown[i] + vcostup[i + 17];
			ans = min(ans,cost);
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