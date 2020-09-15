/*
ID: leeyupeng
LANG: C++11
PROG: test
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG test
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
class  Solution
{
private:

public:
	void PROG() {
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