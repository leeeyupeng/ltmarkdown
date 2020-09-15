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
public:
	void PROG() {
		cin >> N;

		vector<vector<string>> dp;
		vector<int> vans(7,0);
		dp.insert(dp.begin(), NMAX + 1, vector<string>(MAX + 1, ""));
		dp[1][1] = "I";
		dp[5][1] = "V";
		dp[10][2] = "X";
		dp[50][2] = "L";
		dp[100][3] = "C";
		dp[500][3] = "D";
		dp[1000][4] = "M";
		for (int i = 1; i <= N; i++) {
			int value = i;
			int pos = 1;
			for (int j = 1; j <= MAX; j++) {
				int posvalue = value % 10;

				dp[i][j] = "";
				if (posvalue == 0) {
				}
				else if (posvalue == 1) {
					dp[i][j] = dp[pos][j];
				}
				else  if (posvalue <= 3) {
					for (int k = 0; k < posvalue; k++) {
						dp[i][j] += dp[pos][j];
					}
				}
				else if (posvalue == 4) {
					dp[i][j] = dp[pos][j] + dp[5*pos][j];
				}
				else if (posvalue == 5) {
					dp[i][j] = dp[5 * pos][j];
				}
				else if (posvalue <= 8) {
					dp[i][j] = dp[5 * pos][j];
					for (int k = 5; k < posvalue; k++) {
						dp[i][j] += dp[pos][j];
					}
				}
				else if (posvalue == 9) {
					dp[i][j] = dp[pos][j] + dp[pos * 10][j];
				}

				pos = pos * 10;
				value = value / 10;
				if (value == 0) {
					break;
				}
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