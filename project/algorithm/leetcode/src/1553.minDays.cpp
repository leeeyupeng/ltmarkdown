#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
	struct Branch {
		int remain;
		int day;
		int valday;
		Branch(int _remain, int _day) :remain(_remain),day(_day),valday(0){
			valday = day + log(_remain + 2) / log(3);
		}
		bool operator <(Branch a) const { return valday < a.valday; }
		bool operator >(Branch a) const { return valday > a.valday; }
	};
public:
	int minDays(int n) {
		Branch b(n, 0);
		priority_queue<Branch, vector<Branch>, greater<Branch>> q;
		q.push(b);
		int valday = 0;
		int ans = 0;
		unordered_set<int> us;
		while (!q.empty()) {
			Branch top = q.top();			
			q.pop();
			if (us.find(top.remain) != us.end()) { continue; }
			else { us.insert(top.remain); }
			if (top.remain == 0) { ans = top.valday; break; }

			if ((top.remain & 0x1) == 0x0) {
				q.push(Branch(top.remain >> 1, top.day+1));
				
			}
			if (top.remain % 3 == 0) {
				q.push(Branch(top.remain / 3 , top.day+1));
			}
			q.push(Branch(top.remain - 1, top.day+1));
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	int n = 2 * 1000000000;
//	int ans = s.minDays(n);
//	cout << ans << endl;
//	system("PAUSE");
//
//	return 0;
//
//}