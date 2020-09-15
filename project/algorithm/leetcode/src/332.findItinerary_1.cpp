#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
private:
	bool cmp(vector<string>& a, vector<string>& b) {
		if (a[0] == b[0]) {
			return a[1] < b[1];
		}
		return a[0] < b[0];
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		using std::placeholders::_1;
		using std::placeholders::_2;
		auto sortcmp = std::bind(&Solution::cmp, this, _1, _2);
		int ticketsnums = tickets.size();
		sort(tickets.begin(), tickets.end(), sortcmp);
		vector<bool> visit(ticketsnums);
		for (int i = 0; i < ticketsnums; i++) {
			visit[i] = false;
		}
		vector<string> ans;		
		string last = "JFK";
		ans.push_back(last);
		for (int i = 0; i < ticketsnums; i++) {
			for (int j = 0; j < ticketsnums; j++)
			{
				if (visit[j] == false && tickets[j][0] == last) {
					visit[j] = true;
					last = tickets[j][1];
					ans.push_back(last);
					break;
				}
			}
		}
		return ans;
	}
};