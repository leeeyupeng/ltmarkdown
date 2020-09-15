#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
using namespace std;

#include "tree/MinHeap_2.h"
using namespace lt::tree;
class Solution {
#define CHARMAX 26
	struct TrieNode {
		char c;
		TrieNode* parent;
		TrieNode* arr[CHARMAX];
		int length = 0;
		int count = 0;
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
				node->arr[index]->parent = node;
				node->arr[index]->c = word[i];
				node->arr[index]->length = node->length + 1;
			}
			node = node->arr[index];
		}
		node->count ++;
	}

	bool cmp(TrieNode* const &a,TrieNode* const &b) {
		if (a->count== b->count) {
			TrieNode* aa = const_cast<TrieNode*>(a);
			TrieNode* bb = const_cast<TrieNode*>(b);
			while (aa->length > bb->length) { aa = aa->parent; }
			if (aa == bb) { return false; }
			while (bb->length > aa->length) { bb = bb->parent; }
			if (aa == bb) { return true; }
			while (aa->parent != bb->parent) { aa = aa->parent; bb = bb->parent; }
			return getIndex(aa->c) < getIndex(bb->c);
		}
		return a->count > b->count;
	}
	MinHeap<TrieNode*>* heap;
	void DFS(TrieNode* node) {
		if (node->count > 0) {
			heap->Push(node);
		}
		for (int i = 0; i < CHARMAX; i++) {
			if (node->arr[i] != NULL) {
				DFS(node->arr[i]);
			}
		}
	}
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		trie = new TrieNode();
		int n = words.size();
		for (int i = 0; i < n; i++) {
			Insert(words[i]);
		}
		using std::placeholders::_1;
		using std::placeholders::_2;
		auto bound_cmp = std::bind(&Solution::cmp, this, _1, _2);
		heap = new MinHeap<TrieNode*>(bound_cmp);

		DFS(trie);

		vector<string> ans;
		for (int i = 0; i < k; i++) {
			TrieNode* node = heap->Top();
			heap->Pop();
			string str;
			while (node->parent != NULL) {
				str.push_back(node->c);
				node = node->parent;
			}
			reverse(str.begin(), str.end());
			ans.push_back(str);
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<string> words =
//	{
//"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"
//};
//	int k = 4;
//	s.topKFrequent(words,k);
//	system("PAUSE");
//
//	return 0;
//
//}