#pragma once
#include"leetcode.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define null 0
TreeNode *GetTree(vector<int>& tree);