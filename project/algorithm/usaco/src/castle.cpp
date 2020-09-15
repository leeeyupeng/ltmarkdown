/*
ID: leeyupeng
LANG: C++11
PROG: castle
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG castle
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif
#define NMMAX 50
struct Node
{
	int walls=0;
	int roomid=0;
};
class  Solution
{
private:
	int N, M;
	Node map[NMMAX][NMMAX];
	int rooms[NMMAX*NMMAX + 1]{0};
	void FloodFill(int i, int j) {
		if (i > 0 && !(map[i][j].walls & 0x1) && !(map[i - 1][j].walls & 0x4)) {
			if (map[i - 1][j].roomid == 0) {
				rooms[map[i][j].roomid]++;
				map[i - 1][j].roomid = map[i][j].roomid;
				FloodFill(i-1,j);
			}
		}

		if (i < N - 1 && !(map[i][j].walls & 0x4) && !(map[i + 1][j].walls & 0x1)) {
			if (map[i + 1][j].roomid == 0) {
				rooms[map[i][j].roomid]++;
				map[i + 1][j].roomid = map[i][j].roomid;
				FloodFill(i + 1, j);
			}
		}

		if (j > 0 && !(map[i][j].walls & 0x2) && !(map[i][j-1].walls & 0x8)) {
			if (map[i][j-1].roomid == 0) {
				rooms[map[i][j].roomid]++;
				map[i][j-1].roomid = map[i][j].roomid;
				FloodFill(i, j-1);
			}
		}

		if (j < M-1 && !(map[i][j].walls & 0x8) && !(map[i][j + 1].walls & 0x2)) {
			if (map[i][j + 1].roomid == 0) {
				rooms[map[i][j].roomid]++;
				map[i][j + 1].roomid = map[i][j].roomid;
				FloodFill(i, j + 1);
			}
		}
	}
public:
	void PROG() {
		cin >> N >> M;
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				cin >> map[i][j].walls;
			}
		}

		int roomidcount = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j].roomid == 0) {
					roomidcount++;
					map[i][j].roomid = roomidcount;
					rooms[map[i][j].roomid]++;
					FloodFill(i,j);
				}
			}
		}

		int ansroomnums = roomidcount;
		int ansroomlarget = 0;
		for (int i = 1; i <= roomidcount; i++) {
			ansroomlarget = max(ansroomlarget, rooms[i]);
		}
		cout << ansroomnums << endl;
		cout << ansroomlarget << endl;

		int anslarget = 0;
		int ansi;
		int ansj;
		int dir = 0;
		for (int i = 0; i < N; i++) {
			for (int j = M-1; j >=0; j--) {
				if (j > 0 && map[i][j].roomid != map[i][j - 1].roomid) {
					if (anslarget < rooms[map[i][j].roomid] + rooms[map[i][j - 1].roomid]) {
						anslarget = rooms[map[i][j].roomid] + rooms[map[i][j - 1].roomid];
						ansi = i;
						ansj = j;
						dir = 0x2;
					}
				}
				if (i < N - 1 && map[i][j].roomid != map[i+1][j].roomid) {
					if (anslarget < rooms[map[i][j].roomid] + rooms[map[i + 1][j].roomid]) {
						anslarget = rooms[map[i][j].roomid] + rooms[map[i + 1][j].roomid];
						ansi = i;
						ansj = j;
						dir = 0x4;
					}
				}
			}
		}

		cout << anslarget << endl;
		cout << ansj + 1 << " " << ansi + 1 <<" "<< (dir == 0x2 ? "N" : "E") << endl;
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