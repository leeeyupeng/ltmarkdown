#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/n-queens/
class Solution {
public:
	int N;
	vector<vector<char>> vFlag;

	vector<vector<string>> vSolutions;

	void SetFlag(vector<vector<int>>& vRecord, int x, int y)
	{
		for (int i = x + 1; i < N; i++)
		{
			if (vFlag[i][y] == 0) {
				vFlag[i][y] = -1;
				vRecord.push_back({i,y});
			}
		}
		//for (int j = 0; j < N; j++) {
		//	if (vFlag[x][j] == 0) {
		//		vFlag[x][j] = -1;
		//		vRecord.push_back({ x,j });
		//	}
		//}
		for (int i = x + 1, j = y + 1; i < N&& j < N; i++, j++) {
			if (vFlag[i][j] == 0) {
				vFlag[i][j] = -1;
				vRecord.push_back({ i,j });
			}
		}
		for (int i = x + 1, j = y - 1; i < N && j >= 0; i++, j--) {
			if (vFlag[i][j] == 0) {
				vFlag[i][j] = -1;
				vRecord.push_back({ i,j });
			}
		}
	}

	void RevertFlag(vector<vector<int>>& vRecord) {
		for (int i = 0; i < vRecord.size(); i++) {
			vFlag[vRecord[i][0]][vRecord[i][1]] = 0;
		}
	}

	void SaveSolution(vector<vector<char>> vFlag) {
		vector<string> vSulution(N);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++) {
				vSulution[i].push_back(vFlag[i][j]==1?'Q':'.');
			}
		}
		vSolutions.push_back(vSulution);

	}
	void DFS(int index)
	{
		if (index == N) {
			SaveSolution(vFlag);
			return;
		}

		for (int i = 0; i < N; i++) {
			if (vFlag[index][i] == 0) {
				vFlag[index][i] = 1;

				vector<vector<int>> vRecord;
				SetFlag(vRecord,index,i);

				DFS(index+1);
				
				RevertFlag(vRecord);
				vFlag[index][i] = 0;
			}			
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		N = n;
		vFlag.clear();
		vFlag.insert(vFlag.begin(), n, vector<char>(n,0));

		DFS(0);

		return vSolutions;
	}
};