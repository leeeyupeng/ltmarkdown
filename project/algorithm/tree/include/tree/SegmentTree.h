#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;
namespace tree
{
	class SegmentTree
	{
	private:
		struct SegmentNode
		{
			int left;
			int right;
			int value;
			int count;
			SegmentNode() { left = 0; right = 0; value = 0; count = 0; }
		};
		vector<SegmentNode> tree;
	public:
		SegmentTree(int left,int right, vector<int>& vvalue) {
			tree.clear();
			tree.insert(tree.begin(), (right - left + 1) * 4, {});

			BuildTree(1, left, right, vvalue);
		}
		void BuildTree(int k, int left, int right,vector<int>& vvalue) {
			tree[k].left = left;
			tree[k].right = right;
			if (left == right) { tree[k].value = vvalue[left]; return; }
			int mid = (left + right) >> 1;
			BuildTree(k << 1, left, mid, vvalue);
			BuildTree(k << 1 | 1, mid + 1, right, vvalue);
			tree[k].value = tree[k << 1].value + tree[k << 1 | 1].value;
		}
		void Insert(int k,int left, int right) {
			if (tree[k].left <= left && tree[k].right >= right) {
				if (tree[k].left == tree[k].right) { tree[k].count++; return; }
				int mid = (tree[k].left + tree[k].right) >> 1;
				if(tree[k].left == left && tree[k].right == right){
					tree[k].count++; return;
				}
				if (mid >= left) {
					Insert(k << 1, left, min(mid,right));
				}
				if (mid < right) {
					Insert(k << 1 | 1, max(left,mid + 1), right);
				}
			}
		}
		void Delete(int k,int left, int right) {
			if (tree[k].left <= left && tree[k].right >= right) {
				if (tree[k].left == tree[k].right) { tree[k].count--; return; }
				int mid = (tree[k].left + tree[k].right) >> 1;
				if (tree[k].left == left && tree[k].right == right) {
					tree[k].count--; return;
				}
				if (mid >= left) {
					Delete(k << 1, left, min(mid, right));
				}
				if (mid <right) {
					Delete(k << 1 | 1, max(left, mid + 1), right);
				}
			}
		}
		int GetValue(int k,int left, int right) {
			if (tree[k].left <= left && tree[k].right >= right) {
				if (tree[k].left == tree[k].right) { 
					if(tree[k].count>0)return tree[k].value;
					else return 0; 
				}
				int mid = (tree[k].left + tree[k].right) >> 1;
				if (tree[k].left == left && tree[k].right == right) {
					if(tree[k].count>0) return tree[k].value;
				}
				int value = 0;
				if (mid >= left) {
					value += GetValue(k << 1, left, min(mid, right));
				}
				if (mid < right) {
					value += GetValue(k << 1 | 1, max(left, mid + 1), right);
				}
				return value;
			}
			return 0;
		}
	};
}