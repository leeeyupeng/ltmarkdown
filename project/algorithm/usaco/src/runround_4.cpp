/*
ID: leeyupeng
LANG: C++11
PROG: runround
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
#define PROG runround
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:
	unsigned int M;
	vector<char> vM;
	vector<char> vChar{ '1','2','3','4','5','6','7','8','9' };
	vector<bool> vFlag{ false,false,false,false,false,false,false,false,false,false };
	bool IsRunaroundNumbers(int n) {
		vector<char>& number = vChar;
		vector<bool> vvFlag(n, false);
		int start = 0;
		int index = (start + (number[start]-'0')) % n;
		int count = 0;
		while (count < n) {
			if (vvFlag[index] == true) { return false; }
			vvFlag[index] = true;
			count++;
			index = (index + (number[index] - '0')) % n;
		}
		return true;
	}
	bool cmp(vector<char>& vM, vector<char>& vChar) {
		for (int i = 0; i < vM.size(); i++) {
			if (vM[i] > vChar[i]) { return false; }
			if(vM[i] < vChar[i]) { return true; }
		}
		return false;
	}
	void permutation(int index,int n) {
		if (index == n) {
			if (n > vM.size() || (n == vM.size() && cmp(vM, vChar))) {
				if (IsRunaroundNumbers(n)) {
					for (int i = 0; i < n; i++) {
						cout << vChar[i];
					}
					cout << endl;
					exit(0);
				}
			}
			return;
		}

		for (int i = 1; i <= 9; i++) {
			if (vFlag[i] == false) {
				vFlag[i] = true;
				vChar[index] = i + '0';
				permutation(index + 1, n);
				vFlag[i] = false;
			}
		}
	}
public:
	void PROG() {
		cin >> M;
		unsigned int number = M;
		while (number != 0) {
			int d = number % 10;
			vM.push_back(d+'0');
			number /= 10;
		}
		reverse(vM.begin(), vM.end());

		for (int i = vM.size(); i <= 9; i++) {
			permutation(0, i);
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
//	fclose(stdin);
//	fclose(stdout);
//#endif
//	return 0;
//}