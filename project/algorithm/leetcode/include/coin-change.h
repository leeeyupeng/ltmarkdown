#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//https://leetcode-cn.com/problems/coin-change/
namespace dp
{
	class Solution {
	public:
		int ans = INT_MAX;
		void dfs( vector<int>& coins, int amount,int index,int cnt)
		{
			if (index < 0) {
				return;
			}
			for (int c = amount / coins[index]; c >= 0; c--) 
			{
				int na = amount - c * coins[index];
				int ncnt = cnt + c;
				if (na == 0) {
					ans = ncnt < ans ? ncnt : ans;
					break;//ºÙ÷¶1
				}
				if (ncnt + 1 >= ans) {
					break; //ºÙ÷¶2
				}
				dfs(coins, na, index - 1, ncnt);
			}
		}
		int coinChange(vector<int>& coins, int amount) {
			sort(coins.begin(), coins.end());

			dfs( coins, amount, coins.size() - 1,0);
			if (ans == INT_MAX)
			{
				return -1;
			}
			return ans;
		}
	};
}