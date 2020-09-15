#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#if defined(linux)
#include<memory.h>
#include<limits.h>
#endif
using namespace std;

#define CHARNUMS 26
class Solution {
private:
	struct Node {
		bool success;
		Node* child[26];
		Node() :success(false) {
			memset(child,0,sizeof(Node*)*CHARNUMS);
		}
	};
	Node* root;
	void AddWord(string word) {
		int n = word.length();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->child[word[i] - 'a'] == NULL) {
				node->child[word[i] - 'a'] = new Node();
			}
			node = node->child[word[i] - 'a'];
		}
		node->success = true;
	}
	vector<bool> visit;
	int sn;
	bool dfs(string &s, int index, Node* node) {
		if (index == sn) {
			return node->success;
		}

		bool flag = false;		
		if (node->success == true) {
			if (visit[index]==false) {
				flag = dfs(s, index, root);
				if (flag) { return flag; }
				visit[index] = true;
			}
		}
		int key = s[index] - 'a';
		if (node->child[key] == NULL) { return false; }
		flag = dfs(s, index + 1, node->child[key]);		
		return flag;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		root = new Node();
		int wordnums = wordDict.size();
		for (int i = 0; i < wordnums; i++) {
			AddWord(wordDict[i]);
		}
		sn = s.length();
		visit = vector<bool>(sn);
		for (int i = 0; i < sn; i++) { visit[i] = false; }
		bool ans = dfs(s,0,root);
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	string str = "leetcode";
//	vector<string> wordDict = {
//"leet","code"
//	};
//	bool ans = s.wordBreak(str, wordDict);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}