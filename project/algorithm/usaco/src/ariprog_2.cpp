/*
ID: leeyupeng
LANG: C++11
PROG: ariprog
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define PROG ariprog
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define MMAX 250
class  Solution
{
private:
	int N;
	int M;
	bool bisquares[MMAX * MMAX * 2 + 2] = {false};
public:
	void PROG() {
		cin >> N;
		cin >> M;

		int s;
		int smax = M * M+M*M;
		for (int i = 0; i <= M; i++) {
			for (int j = i; j <= M; j++) {
				s = i * i + j * j;
				bisquares[s] = true;
			}
		}
		int imax = smax - (N-1);
		int jmax = smax / (N-1);
		int ab;
		int i, j,k;
		int jbase = 1;
		if (N == 3)jbase = 1;
		else if (N < 6)jbase = 4;
		else if (N < 12)jbase = 12;
		else { jbase = 84; }
		bool jbaseflag = false;
		bool flag = false;
		for (j = jbase; j <= jmax; j+=jbase) {
			imax = smax - (N - 1) * j;
			for (i = 0; i <= imax; i++) {			
				for (k = N-1; k >=0; k--) {
					ab = i + k * j;
					if (bisquares[ab] == false) { break; }
				}
				if (k == -1) {
					flag = true;
					if (jbaseflag == false) { jbase = j; jbaseflag = true; }
					cout << i << " " << j << endl;
				}
			}
		}

		if (flag == false) {
			cout << "NONE" << endl;
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