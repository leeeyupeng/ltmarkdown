#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
private:
	int timenums;
	int map[100000];
	int res = 0;
	void updatebitree(int index,int value) {
		while (index < timenums+1) {
			map[index] = max(map[index],value);
			index = index + (index&((~index) + 1));
		}
	}
	int getmaxbitree(int index) {
		res = 0;
		while (index > 0) {
			res = max(res,map[index]);
			index = index - (index&((~index) + 1));
		}
		return res;
	}
	vector<int> endTime;
	bool cmp(const int& a, const int& b) {
		return endTime[a] <= endTime[b];
	}
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();

		vector<int> startTimesort = startTime;
		sort(startTimesort.begin(),startTimesort.end());
		vector<int> endTimesort = endTime;
		sort(endTimesort.begin(), endTimesort.end());
		vector<int> timesort;
		int i = 0, j = 0;
		int lastvalue = 0;
		while (i < n || j < n) {
			if (i < n&&j < n) {
				if (startTimesort[i] < endTimesort[j]) {
					if (lastvalue < startTimesort[i]) {
						timesort.push_back(startTimesort[i]);
						lastvalue = startTimesort[i];
					}
					i++;
				}
				else
				{
					if (lastvalue < endTimesort[j]) {
						timesort.push_back(endTimesort[j]);
						lastvalue = endTimesort[j];
					}
					j++;
				}
			}
			else if (i < n) {
				if (lastvalue < startTimesort[i]) {
					timesort.push_back(startTimesort[i]);
					lastvalue = startTimesort[i];
				}
				i++;
			}
			else if (j < n) {
				if (lastvalue < endTimesort[j]) {
					timesort.push_back(endTimesort[j]);
					lastvalue = endTimesort[j];
				}
				j++;
			}
		}
		unordered_map<int, int> sortmap;
		timenums = timesort.size();
		for (int i = 0; i < timenums; i++) {
			sortmap[timesort[i]]=i + 1;
		}

		this->endTime = endTime;
		vector<int>  v(n);
		for (int i = 0; i < n; i++) {
			v[i] = i;
		}
		using std::placeholders::_1;
		using std::placeholders::_2;
		auto bound_cmp = std::bind(&Solution::cmp,this, _1, _2);
		sort(v.begin(),v.end(), bound_cmp);

		int index;
		for (int i = 0; i < n; i++) {
			index = v[i];
			updatebitree(sortmap[endTime[index]],getmaxbitree(sortmap[startTime[index]]) + profit[index]);
		}
		return getmaxbitree(timenums);
	}
};

//int main()
//{
//	Solution s;
//	vector<int> startTime = {
//1,2,3,4,6
//	};
//	vector<int> endTime = {
//3,5,10,6,9
//	};
//	vector<int> profit = {
//20,20,100,70,60
//	};
//
//	int ans = s.jobScheduling(startTime, endTime, profit);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}