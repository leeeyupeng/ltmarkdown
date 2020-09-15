#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<unordered_map>
using namespace std;

#define MAX 1000000001
class Solution {
private:
	unordered_map<int,int> map;
	int res = 0;
	void updatebitree(int index,int value) {
		while (index < MAX) {
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
		return endTime[a] < endTime[b];
	}
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
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
			updatebitree(endTime[index],getmaxbitree(startTime[index]) + profit[index]);
		}
		return getmaxbitree(endTime[index]);
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