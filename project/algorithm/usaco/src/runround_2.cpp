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
	bool IsRunaroundNumbers(vector<char>& vvChar,int n) {
		vector<char>& number = vvChar;
		vector<bool> vFlag(n, false);
		int start = 0;
		int index = (start + (number[start]-'0')) % n;
		int count = 0;
		while (count < n) {
			if (vFlag[index] == true) { return false; }
			vFlag[index] = true;
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
	void permutation(vector<char> vvChar,int index,int n) {
		if (index == n) {
			if (n > vM.size() || (n == vM.size() && cmp(vM, vvChar))) {
				if (IsRunaroundNumbers(vvChar,n)) {
					for (int i = 0; i < n; i++) {
						cout << vvChar[i];
					}
					cout << endl;
					exit(0);
				}
			}
			return;
		}
		for (int i = index; i < 9; i++) {
			//sort(vChar.begin() + index,vChar.end());
			//swap(vChar[index],vChar[i]);
			//char c = vChar[i];
			//for (int j = i; j > index; j--) {
			//	vChar[j] = vChar[j - 1];
			//}
			//vChar[index] = c;
			//char c = vChar[i];
			//vChar[i] = vChar[index];
			//vChar[i - 1] = vChar[index];		
			//vChar[index] = c;
			swap(vvChar[index], vvChar[i]);
			permutation(vvChar,index+1,n);
			
			//for (int j = index; j < i; j++) {
			//	vChar[j] = vChar[j + 1];
			//}
			//vChar[i] = c;
			//swap(vChar[index], vChar[i]);
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
		vector<char> vChar{ '1','2','3','4','5','6','7','8','9' };
		for (int i = vM.size(); i <= 9; i++) {
			permutation(vChar,0, i);
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