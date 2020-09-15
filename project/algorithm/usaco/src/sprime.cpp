/*
ID: leeyupeng
LANG: C++11
PROG: sprime
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
#define PROG sprime
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	int N;
	bool IsPrime(int p) {
		int s = sqrt(p);
		for (int i = 2; i <= s; i++) {
			if (p%i == 0) { return false; }
		}
		return true;
	}
public:
	void PROG() {
		cin >> N;
		vector<int> v{2,3,5,7};
		vector<int> vans;
		vector<int> v2{ 1,3,5,7,9 };
		for (int i = 1; i < N; i++) {
			vans.clear();
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v2.size(); k++) {
					if (IsPrime(v[j] * 10 + v2[k])) {
						vans.push_back(v[j] * 10 + v2[k]);
					}
				}
			}
			v = vans;
		}

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