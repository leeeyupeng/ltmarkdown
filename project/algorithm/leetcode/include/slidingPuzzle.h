// https://leetcode-cn.com/problems/sliding-puzzle/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
private:
	set<int> s;
	int success;
	int step;
	vector<vector<int>> vvboard = {
			{1,2,3},
			{4,5,0}
	};;
	int GetValue(vector<vector<int>>& board) {
		int value = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				value <<= 3;
				value += board[i][j];
			}
		}
		return value;
	}

	void SetValue(vector<vector<int>>& board, int value, char& posx, char& posy) {
		for (int i = 1; i >= 0; i--) {
			for (int j = 2; j >= 0; j--) {
				board[i][j] = value & 0x07;
				value >>= 3;
				if (board[i][j] == 0) {
					posx = i;
					posy = j;
				}
			}
		}
	}

	int BFS(int iboard, int step) {
		queue<int> q;
		q.push(iboard);

		int iiboard;
		char posx; char posy;
		int tempiboard;
		queue<int> tempq;
		while (!q.empty()) {
			while (!q.empty()) {
				iiboard = q.front();
				if (iiboard == success) { return step; }
				q.pop();

				s.insert(iiboard);

				SetValue(vvboard, iiboard, posx, posy);
				if (posx > 0) {
					swap(vvboard[posx][posy], vvboard[posx - 1][posy]);
					tempiboard = GetValue(vvboard);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
					swap(vvboard[posx][posy], vvboard[posx - 1][posy]);
				}
				else if (posx < 1) {
					swap(vvboard[posx][posy], vvboard[posx + 1][posy]);
					tempiboard = GetValue(vvboard);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
					swap(vvboard[posx][posy], vvboard[posx + 1][posy]);
				}

				if (posy > 0) {
					swap(vvboard[posx][posy], vvboard[posx][posy - 1]);
					tempiboard = GetValue(vvboard);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
					swap(vvboard[posx][posy], vvboard[posx][posy - 1]);
				}
				if (posy < 2) {
					swap(vvboard[posx][posy], vvboard[posx][posy + 1]);
					tempiboard = GetValue(vvboard);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
					swap(vvboard[posx][posy], vvboard[posx][posy + 1]);
				}
			}
			swap(q, tempq);
			step++;
		}
		return -1;
	}
public:
	int slidingPuzzle(vector<vector<int>>& board) {
		success = GetValue(vvboard);
		step = 0;
		int ans = BFS(GetValue(board), step);
		return ans;
	}
};