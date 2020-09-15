#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define CHARMAX 26
namespace longestWord {
	struct TrieNode {
		char c;
		TrieNode* arr[CHARMAX];
		bool flag = false;
	};
	class Trie {
	private:
		TrieNode *root = new TrieNode();
		inline int getIndex(char c) {
			return c - 'a';
		}
		inline char getChar(int index) {
			return 'a' + index;
		}

		int anslength;
		string ans;
	public:
		void Insert(string word) {
			int n = word.length();
			int index;
			TrieNode* node = root;
			for (int i = 0; i < n; i++) {
				index = getIndex(word[i]);
				if (node->arr[index] == NULL) {
					node->arr[index] = new TrieNode();
					node->arr[index]->c = word[i];
				}
				node = node->arr[index];
			}
			node->flag = true;
		}

		void DFS(string& res, TrieNode* node) {
			if (node == NULL) {
				if (anslength < res.length()) {
					anslength = res.length();
					ans = res;
				}
				return;
			}

			if (node->flag == true) {
				res.push_back(node->c);
				for (int i = 0; i < CHARMAX; i++) {
					DFS(res, node->arr[i]);
				}
				res.pop_back();
			}
		}
		string GetLongestWord()
		{
			ans = "";
			anslength = 0;
			string res;
			TrieNode* node = root;
			for (int i = 0; i < CHARMAX; i++) {
				if (node->arr[i] != NULL) {
					DFS(res, node->arr[i]);
				}
			}
			return ans;
		}
	};
}
using namespace longestWord;
class Solution {
public:
	string longestWord(vector<string>& words) {
		int n = words.size();
		if (n == 0) { return ""; }
		Trie trie;
		for (int i = 0; i < n; i++) {
			trie.Insert(words[i]);
		}

		return trie.GetLongestWord();
	}
};

//int main()
//{
//	Solution s;
//	vector<string> words = 
//	{ 
//"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"
//	};
//	string ans = s.longestWord(words);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}