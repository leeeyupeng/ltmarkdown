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
public:
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		int i, j;
		int cursor = 0;
		for (i = 1; i < (n>>1); i++) {
			if (n%i != 0) { continue; }
			cursor = 0;
			j = i;
			
			while (j < n) {
				if (s[cursor] == s[j]) { 
					cursor++;
					if (cursor >= i) { cursor = 0; }
					j++; 
					continue; 
				}
				else { break; }				
			}
			if (j == n && cursor == 0) { return true; }
		}
		return false;
	}
};