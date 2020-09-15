#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> sdigit;
		int n = tokens.size();
		int d1, d2;
		for (int i = 0; i < n; i++) {
			if (tokens[i] == "+") {
				d1 = sdigit.top();
				sdigit.pop();
				d2 = sdigit.top();
				sdigit.pop();
				sdigit.push(d2 + d1);
			}
			else if(tokens[i] == "-") {
				d1 = sdigit.top();
				sdigit.pop();
				d2 = sdigit.top();
				sdigit.pop();
				sdigit.push(d2 - d1);
			}
			else if (tokens[i] == "*") {
				d1 = sdigit.top();
				sdigit.pop();
				d2 = sdigit.top();
				sdigit.pop();
				sdigit.push(d2 * d1);
			}
			else if (tokens[i] == "/") {
				d1 = sdigit.top();
				sdigit.pop();
				d2 = sdigit.top();
				sdigit.pop();
				sdigit.push(d2 / d1);
			}
			else {
				sdigit.push(stoi(tokens[i]));
			}
		}

		return sdigit.top();
	}
};