
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

//https://leetcode-cn.com/problems/super-egg-drop/

class Solution {
public:

	int dp[101][1001] = {0};
	int superEggDrop(int K, int N) {
		int i, j;
		for (i = 1; i <= K; i++)
		{
			dp[i][1] = 1;
		}
		for (j = 1; j <= N; j++)
		{
			dp[1][j] = j;
		}
		int temp;
		int ff;
		int fMin, fMax;
		int fMedian;
		int median,left, right;
		int ii, jj;
		for (i = 2; i <= K; i++)
		{
			for (j = 2; j <= N; j++)
			{	
				fMin = 1; fMax = j;
				while (fMin + 1 < fMax)
				{
					fMedian = (fMin + fMax) / 2;
					left = dp[i - 1][fMedian - 1];
					right = dp[i][j - fMedian];
					if (left < right)
					{
						fMin = fMedian + 1;
					}
					else if (left > right)
					{
						fMax = fMedian - 1;
					}
					else
					{
						fMin = fMedian;
						fMax = fMedian;
					}
				}
				median = min(max(dp[i - 1][fMin - 1] + 1, dp[i][j - fMin] + 1)
					, max(dp[i - 1][fMax - 1] + 1, dp[i][j - fMax] + 1));
				dp[i][j] = median;
			}
		}

 		return dp[K][N];
	}
};

//class Solution {
//public:
//	int dp[101][1001] = { 0 };
//	int superEggDrop(int K, int N) {
//		int i, j, f;
//		for (i = 1; i <= K; i++)
//		{
//			dp[i][1] = 1;
//		}
//		for (j = 1; j <= N; j++)
//		{
//			dp[1][j] = j;
//		}
//
//		int temp;
//		for (i = 2; i <= K; i++)
//		{
//			for (j = 2; j <= N; j++)
//			{
//				dp[i][j] = max(dp[i - 1][0] + 1, dp[i][j - 1] + 1);
//				for (f = 2; f <= j; f++)
//				{
//					temp = max(dp[i - 1][f - 1] + 1, dp[i][j - f] + 1);
//					dp[i][j] = min(dp[i][j], temp);
//				}
//			}
//		}
//
//		return dp[K][N];
//	}
//};