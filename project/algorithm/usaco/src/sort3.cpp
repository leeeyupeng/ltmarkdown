/*
ID: leeyupeng
LANG: C++11
PROG: sort3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG sort3
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
	vector<int> vN;
	vector<int> vSort;
	vector<int> vDFS;
	int ans;
	void DFS(int index,int count) {
		if (index == N) {
			ans = min(ans, count); return;
		}
		if (vDFS[index] == vSort[index]) {
			int i = 0;
			for (i = index+1; i < N; i++) {
				if (vDFS[i] != vSort[i]) { break; }
			}
			index = i;
			if (index == N) {
				ans = min(ans, count); return;
			}
		}

		//int mincount = 0;
		//for (int i = index; i < N; i++) {
		//	if (vDFS[i] != vSort[i]) {
		//		mincount++;
		//	}
		//}
		//if ((mincount+1)/2+count >= ans) { return; }

		for (int i = index + 1; i < N; i++) {
			if (vDFS[index] > vDFS[i]) {
				if (vSort[index] == vDFS[i] && vDFS[index] == vSort[i]) {
					swap(vDFS[index], vDFS[i]);
					DFS(index + 1, count + 1);
					swap(vDFS[index], vDFS[i]);
					return;
				}
			}
		}
		for (int i = N-1; i > index; i--) {
			if (vDFS[index] > vDFS[i]) {
				if (vSort[index] == vDFS[i]) {
					swap(vDFS[index], vDFS[i]);
					DFS(index + 1, count + 1);
					swap(vDFS[index], vDFS[i]);
					return;
				}
			}
		}
	}
public:
	void PROG() {
		cin >> N;
		vN.insert(vN.begin(),N,0);
		for (int i = 0; i < N; i++) {
			cin >> vN[i];
		}
		vSort = vN;
		vDFS = vN;

		sort(vSort.begin(), vSort.end());
		ans = N*N;
		int count = 0;
		//for (int i = 0; i < N; i++) {
		//	for (int j = i+1; j < N; j++) {
		//		if (vDFS[i] != vDFS[j] &&vSort[i] == vDFS[j] && vSort[j] == vDFS[i]) {
		//			count++;
		//			swap(vDFS[i],vDFS[j]);
		//			break;
		//		}
		//	}
		//}
		DFS(0, count);
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
//#ifdef FILESTREAM
//	fclose(stdin);
//	fclose(stdout);
//#endif
//	return 0;
//}