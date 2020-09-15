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
	vector<bool> vValue{false,false,false,false,false,false,false,false,false,false };
	bool IsRunaroundNumbers(unsigned int number) {
		vector<int> v;
		set<int> s;
		while (number != 0) {
			int d = number % 10;
			if (s.find(d) != s.end()) { return false; }
			if (d == 0) { return false; }
			s.insert(d);
			v.push_back(d);
			number /= 10;
		}
		reverse(v.begin(), v.end());
		int n = v.size();
		vector<bool> vFlag(n, false);
		int start = 0;
		int index = (start + v[start]) % n;
		int count = 0;
		while (count < n) {
			if (vFlag[index] == true) { return false; }
			vFlag[index] = true;
			count++;
			index = (index + v[index]) % n;
		}
		return true;
	}
	void permutation(unsigned int value,int index,int n) {
		if (index == n) {
			if (value > M) {
				if (IsRunaroundNumbers(value)) {
					cout << value<<endl;
					exit(0);
				}
			}
			return;
		}
		for (int i = 1; i <= 9; i++) {
			if (vValue[i] == false) {
				vValue[i] = true;
				permutation(value*10+i, index + 1, n);
				vValue[i] = false;
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
		for (int i = 1; i <= 9; i++) {
			if (i >= vM.size()) {
				permutation(0, 0, i);
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
//	fclose(stdin);
//	fclose(stdout);
//#endif
//	return 0;
//}