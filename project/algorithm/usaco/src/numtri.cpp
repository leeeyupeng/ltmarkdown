/*
ID: leeyupeng
LANG: C++11
PROG: numtri
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG numtri
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	int R;
	int a[1002] = {0};
	int b[1002] = {0};
public:
	void PROG() {
		cin >> R;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> a[j];
			}
			for (int j = i; j > 0; j--) {
				b[j] = max(b[j],b[j-1]) + a[j];
			}
		}

		int ans = 0;
		for (int i = 1; i <= R; i++) {
			ans = max(ans,b[i]);
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