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
		int index;
		Node* child[26];
		Node() :index(-1){
			memset(child,0,sizeof(Node*)*CHARNUMS);
		}
	};
	Node* root;
	void AddWord(string word,int index) {
		int n = word.length();
		Node* node = root;
		for (int i = 0; i < n; i++) {
			if (node->child[word[i] - 'a'] == NULL) {
				node->child[word[i] - 'a'] = new Node();
			}
			node = node->child[word[i] - 'a'];
		}
		node->index = index;
	}
	vector<bool> visit;
	int sn;
	bool checkdfs(string &s, int index, Node* node) {
		if (index == sn) {
			return node->index>=0;
		}

		bool flag = false;
		if (node->index >= 0) {
			if (visit[index] == false) {
				flag = checkdfs(s, index, root);
				if (flag) { return flag; }
				visit[index] = true;
			}
		}
		int key = s[index] - 'a';
		if (node->child[key] == NULL) { return false; }
		flag = checkdfs(s, index + 1, node->child[key]);
		return flag;
	}
	vector<string> wordDict;
	vector<string> ans;
	vector<int> path;
	void addpath() {
		string str;
		for (int i = 0; i < path.size() - 1; i++) {
			str += wordDict[path[i]];
			str.push_back(' ');
		}
		str += wordDict[path[path.size() - 1]];
		ans.push_back(str);
	}
	void dfs(string &s,int index, Node* node) {
		if (index == sn) {
			if (node->index>= 0) {
				path.push_back(node->index);
				addpath();
				path.pop_back();
			}
			return;
		}	

		if (node->index >= 0) {
			//if (visit[index]==false) {
			path.push_back(node->index);
			dfs(s, index, root);
			path.pop_back();
			//visit[index] = true;
		//}
		}

		int key = s[index] - 'a';
		if (node->child[key] != NULL) {
			dfs(s,index + 1, node->child[key]);
		}
	}
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		this->wordDict = wordDict;
		root = new Node();
		int wordnums = wordDict.size();
		for (int i = 0; i < wordnums; i++) {
			AddWord(wordDict[i],i);
		}
		sn = s.length();
		visit = vector<bool>(sn);
		for (int i = 0; i < sn; i++) { visit[i] = false; }
		if (checkdfs(s, 0, root) == true) {
			dfs(s, 0, root);
		}
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	string str = "pineapplepenapple";
//	vector<string> wordDict = {
//"apple", "pen", "applepen", "pine", "pineapple"
//	};
//	vector<string> ans = s.wordBreak(str, wordDict);
//	system("PAUSE");
//
//	return 0;
//}