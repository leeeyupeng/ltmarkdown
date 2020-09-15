#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;


class Solution {
private:

public:
	int calculate(string s) {
		unordered_map<char, int> priority;
		priority.insert({'+',1});
		priority.insert({ '-',1 });
		priority.insert({ '*',2 });
		priority.insert({ '/',2 });
		stack<char> soperator;
		stack<int> sdigit;

		int digit = 0;
		char ope;
		int d1, d2;
		int value;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				sdigit.push(digit);
				digit = 0;

				while (!soperator.empty() && priority[soperator.top()] >= priority[s[i]]) {
					ope = soperator.top();
					soperator.pop();
					d2 = sdigit.top();
					sdigit.pop();
					d1 = sdigit.top();
					sdigit.pop();
					switch (ope)
					{
					case '+':
						value = d1 + d2;
						break;
					case '-':
						value = d1 - d2;
						break;
					case '*':
						value = d1 * d2;
						break;
					case '/':
						value = d1 / d2;
						break;
					}
					sdigit.push(value);
				}
				soperator.push(s[i]);
			}
			else if (s[i] >= '0' && s[i] <= '9') { digit = digit * 10 + s[i] - '0'; }
		}

		sdigit.push(digit);

		while (!soperator.empty()) {
			ope = soperator.top();
			soperator.pop();
			d2 = sdigit.top();
			sdigit.pop();
			d1 = sdigit.top();
			sdigit.pop();
			switch (ope)
			{
			case '+':
				value = d1 + d2;
				break;
			case '-':
				value = d1 - d2;
				break;
			case '*':
				value = d1 * d2;
				break;
			case '/':
				value = d1 / d2;
				break;
			}
			sdigit.push(value);
		}

		return sdigit.top();
	}
};

//int main() {
//
//	Solution s;
//	string v = "2147483647";
//	int ans = s.calculate(v);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}