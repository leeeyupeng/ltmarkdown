// https://leetcode-cn.com/problems/sliding-puzzle/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
private:
	unordered_set<unsigned int> s;
	unsigned int success;
	int step;
	vector<vector<int>> vvboard = {
			{1,2,3},
			{4,5,0}
	};;
	unsigned int GetValue(vector<vector<int>>& board) {
		unsigned int value = 0;
		char x = -1, y = -1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 0) { 
					x = i, y = j; break; 
				}
			}
			if (x != -1) { break; }
		}
		value <<= 2;
		value = x;
		value <<= 2;
		value += y;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				value <<= 3;
				value += board[i][j];
			}
		}
		return value;
	}

	int BFS(unsigned int iboard, int step) {
		queue<unsigned int> q;
		q.push(iboard);

		unsigned int iiboard;
		char posx; char posy;
		unsigned int tempiboard;
		queue<unsigned int> tempq;
		while (!q.empty()) {
			while (!q.empty()) {
				iiboard = q.front();
				if (iiboard == success) { return step; }
				q.pop();

				s.insert(iiboard);
				posx = iiboard >> 20 & 0x03;
				posy = iiboard >> 18 & 0x03;
				unsigned int bit1 = (15 - 9 * posx - 3 * posy);
				unsigned int bit2;
				unsigned int posxvalue2;
				if (posx > 0) {
					bit2 = (15 - 9 * (posx - 1) - 3 * posy);
					unsigned int posxvalue2 = (iiboard >> bit2) & 0x07;
					tempiboard = iiboard + (posxvalue2 << bit1);
					tempiboard = tempiboard & (~(0x07 << bit2));
					tempiboard = tempiboard -(0x01 << 20);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
				}
				else if (posx < 1) {
					bit2 = (15 - 9 * (posx + 1) - 3 * posy);
					unsigned int posxvalue2 = (iiboard >> bit2) & 0x07;
					tempiboard = iiboard + (posxvalue2 << bit1);
					tempiboard = tempiboard & (~(0x07 << bit2));
					tempiboard = tempiboard + (0x01 << 20);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
				}

				if (posy > 0) {
					bit2 = (15 - 9 * (posx)-3 * (posy - 1));
					unsigned int posxvalue2 = (iiboard >> bit2) & 0x07;
					tempiboard = iiboard + (posxvalue2 << bit1);
					tempiboard = tempiboard & (~(0x07 << bit2));
					tempiboard = tempiboard - (0x01 << 18);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
				}
				if (posy < 2) {
					bit2 = (15 - 9 * (posx)-3 * (posy + 1));
					unsigned int posxvalue2 = (iiboard >> bit2) & 0x07;
					tempiboard = iiboard + (posxvalue2 << bit1);
					tempiboard = tempiboard & (~(0x07 << bit2));
					tempiboard = tempiboard + (0x01 << 18);
					if (s.find(tempiboard) == s.end()) {
						tempq.push(tempiboard);
					}
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