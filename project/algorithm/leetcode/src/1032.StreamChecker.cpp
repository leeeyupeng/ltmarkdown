#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define CHARMAX 26
class StreamChecker {
	struct TrieNode {
		char c;
		TrieNode* arr[CHARMAX];
		bool flag = false;
	};
private:
	TrieNode* trie;
	inline int getIndex(char c) {
		return c - 'a';
	}
	inline char getChar(int index) {
		return 'a' + index;
	}
	void Insert(string word) {
		int n = word.length();
		int index;

		TrieNode* node = trie;
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
	vector<TrieNode*>* vNode1;
	vector<TrieNode*>* vNode2;
public:
	StreamChecker(vector<string>& words) {
		trie = new TrieNode();
		int n = words.size();
		for (int i = 0; i < n; i++) {
			Insert(words[i]);
		}

		vNode1 = new vector<TrieNode*>();
		vNode1->push_back(trie);
		vNode2 = new vector<TrieNode*>();
	}

	bool query(char letter) {
		int index = getIndex(letter);
		bool ans = false;
		for (int i = 0; i < vNode1->size(); i++) {
			if ((*vNode1)[i]->arr[index] != NULL) {
				vNode2->push_back((*vNode1)[i]->arr[index]);

				if ((*vNode1)[i]->arr[index]->flag) {
					ans = true;
				}
			}
		}
		swap(vNode1,vNode2);
		vNode1->push_back(trie);
		vNode2->clear();
		return ans;
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */