
#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
//https://leetcode-cn.com/problems/word-ladder/
class Solution {
public:
	///自定义优先级
	struct open {    ///不允许起名为 cmp ？
		int index;
		int distance;
		open(int i,int d)
		{
			index = i;
			distance = d;
		}
		bool operator < (const open &a) const{
			return distance > a.distance;///从小到大，最小值优先。
		}
	};
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.insert(wordList.begin(),beginWord);

		int n = wordList.size();
		int length = beginWord.length();
		int count = 0;
		int count2 = 0;

		vector<int> distance(n);
		priority_queue<open> openDistance;
		vector<int> gDistance(n);

		set<int> s;
		int end = 0;
		for (int i = 0; i < n; i++) { s.insert(i); if (wordList[i] == endWord)end = i; }
		if (end == 0) { return 0; }
		int cur = 0;

		openDistance.push({0,0});

		int i;

		int ans = 0;
		while (!openDistance.empty())
		{
			if (s.find(openDistance.top().index) == s.end()) { openDistance.pop(); continue; }
			open o = openDistance.top();
			openDistance.pop();
			s.erase(s.find(o.index));

			cur = o.index;
			if (cur == end) { 
				ans = o.distance + 1; break; 
			}

			for(set<int>::iterator it = s.begin();it!=s.end();it++)
			{
				i = (*it);

				count = 0;
				for (int l = 0; l < length; l++)
				{
					if (wordList[cur][l] != wordList[i][l])
					{
						count++;
						if (count > 1) { break; }
					}
				}
				if (count == 1) { 
					if (distance[i] == 0)
					{
						count2 = 0;
						for (int l = 0; l < length; l++)
						{
							if (wordList[i][l] != wordList[end][l])
							{
								count2++;
							}
						}

						gDistance[i] = count2;

						distance[i] = distance[cur] + 1;
						openDistance.push({i,distance[i] + gDistance[i]});
					}
					else if(distance[i] > distance[cur] + 1)
					{
						distance[i] = distance[cur] + 1;
						openDistance.push({ i,distance[i] + gDistance[i] });
					}
				}
			}
		}
		return ans;
	}
};