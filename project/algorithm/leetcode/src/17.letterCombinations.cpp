#include"leetcode.h"


class Solution {
private:
	string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	void combine(queue<string>& q, string& mapping) {
		int n = q.size();
		if (n == 0) {
			for (int i = 0; i < mapping.length(); i++) {
				q.push(string(1,mapping[i]));
			}
		}
		else {
			while (n > 0) {
				n--;
				string qq = q.front();
				q.pop();
				for (int i = 0; i < mapping.length(); i++) {
					q.push(qq + string(1, mapping[i]));
				}
			}
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		queue<string> q;
		int n = digits.length();
		for (int i = 0; i < n; i++) {
			combine(q, mapping[digits[i] - '0']);
		}

		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}
};