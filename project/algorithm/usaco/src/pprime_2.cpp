/*
ID: leeyupeng
LANG: C++11
PROG: pprime
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define PROG pprime
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define MAX 100000000
class  Solution
{
private:
	bool IsPrime(int p) {
		int s = sqrt(p);
		for (int i = 2; i <= s; i++) {
			if (p%i == 0) { return false; }
		}
		return true;
	}
public:
	void PROG() {
		int a, b;
		cin >> a >> b;

		vector<int> vans;
		for (int i = 1; i < 100000; i++) {
			int  v = i;

			{
				int p = v;
				int m = v;
				while (m != 0) {
					p = p * 10 + m % 10;
					m /= 10;
				}
				if (p >= a && p <= b && IsPrime(p)) {
					vans.push_back(p);
				}
			}

			{
				int p = v;
				int m = v/10;
				while (m != 0) {
					p = p * 10 + m % 10;
					m /= 10;
				}

				if (p >= a && p <= b && IsPrime(p)) {
					vans.push_back(p);
				}
			}
		}

		sort(vans.begin(), vans.end());
		for (int i = 0; i < vans.size(); i++) {
			cout << vans[i] << endl;
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