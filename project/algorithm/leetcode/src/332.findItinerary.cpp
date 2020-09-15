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
	int ticketsnums;
	map<string, int> us;
	int n;
	vector<vector<int>> vs;
	
	bool cmp(vector<vector<string>>& tickets, int a, int b) {
		return us[tickets[a][1]] < us[tickets[b][1]];
	}
	vector<int> anslist;
	vector<string> ans;
	vector<bool> ticketsflag;
	bool DFS(vector<vector<string>>& tickets,int index,int count) {
		if (count == ticketsnums) {
			return true;
		}
		for (int i = 0; i < vs[index].size(); i++) {
			if (ticketsflag[vs[index][i]] == false) {
				ticketsflag[vs[index][i]] = true;
				anslist.push_back(vs[index][i]);
				if (DFS(tickets, us[tickets[vs[index][i]][1]], count + 1))
				{
					return true;
				}
				anslist.pop_back();
				ticketsflag[vs[index][i]] = false;
			}
		}
		return false;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		ticketsnums = tickets.size();
		for (int i = 0; i < ticketsnums; i++) {
			if (us.find(tickets[i][0]) == us.end()) { us.insert({ tickets[i][0],0}); }
			if (us.find(tickets[i][1]) == us.end()) { us.insert({tickets[i][1],0}); }
		}
		map<string, int>::iterator ite = us.begin();
		int index = 0;
		for (; ite != us.end(); ite++) {
			ite->second = index++;
		}
		n = us.size();
		vs = vector<vector<int>>(n);

		for (int i = 0; i < ticketsnums; i++) {
			
			vs[us[tickets[i][0]]].push_back(i);
		}
		using std::placeholders::_1;
		using std::placeholders::_2;
		auto sortcmp = std::bind(&Solution::cmp, this, tickets, _1, _2);
		for (int i = 0; i < n; i++) {
			sort(vs[i].begin(),vs[i].end(), sortcmp);
		}

		ticketsflag = vector<bool>(ticketsnums);
		for (int i = 0; i < ticketsnums; i++) {
			ticketsflag[i] = false;
		}
		if (DFS(tickets, us["JFK"], 0)) {
			if (anslist.size() > 0) {
				ans.push_back(tickets[anslist[0]][0]);
				for (int i = 0; i < anslist.size(); i++) {
					ans.push_back(tickets[anslist[i]][1]);
				}
			}
		}
		return ans;
	}
};