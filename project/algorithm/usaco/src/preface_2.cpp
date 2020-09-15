/*
ID: leeyupeng
LANG: C++11
PROG: preface
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG preface
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

#define NMAX 3500
#define MAX 4
class  Solution
{
private:
	int N;
	void Add(vector<int> & a, vector<int>& b,int num) {
		for (int i = 1; i < a.size(); i++) {
			a[i] += b[i] * num;
		}
	}
public:
	void PROG() {
		cin >> N;

		vector<vector<int>> dp;
		
		dp.insert(dp.begin(), NMAX + 1, vector<int>(7 + 1, 0));
		dp[1][1] = 1;
		dp[5][2] = 1;
		dp[10][3] = 1;
		dp[50][4] = 1;
		dp[100][5] = 1;
		dp[500][6] = 1;
		dp[1000][7] = 1;
		for (int i = 1; i <= N; i++) {
			if (i == 1 || i == 5 || i == 10 || i == 50 || i == 100 || i == 500 || i == 1000) { continue; }
			int value = i;
			int pos = 1;
			for (int j = 1; j <= MAX; j++) {
				int posvalue = value % 10;

				if (posvalue == 0) {
				}
				else if (posvalue == 1) {
					Add(dp[i],dp[pos], posvalue);
				}
				else  if (posvalue <= 3) {
					Add(dp[i], dp[pos], posvalue);
				}
				else if (posvalue == 4) {
					Add(dp[i], dp[pos], 1);
					Add(dp[i], dp[5*pos], 1);					
				}
				else if (posvalue == 5) {
					Add(dp[i], dp[5 * pos], 1);
				}
				else if (posvalue <= 8) {
					Add(dp[i], dp[5 * pos], 1);
					Add(dp[i], dp[pos], posvalue-5);
				}
				else if (posvalue == 9) {
					Add(dp[i], dp[pos], 10-posvalue);
					Add(dp[i], dp[pos * 10], 1);
				}

				pos = pos * 10;
				value = value / 10;
				if (value == 0) {
					break;
				}
			}
		}

		vector<int> vans(8, 0);
		for (int i = 1; i <= N; i++) {
			Add(vans,dp[i],1);
		}

		vector<char> vchar{'\0','I','V','X','L','C','D','M'};
		for (int i = 1; i <= 7; i++) {
			if (vans[i] != 0) {
				cout << vchar[i] << " " << vans[i] << endl;
			}
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
//#ifdef FILESTREAM
//fclose(stdin);
//fclose(stdout);
//#endif
//	return 0;
//}