#include"leetcode.h"

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    void dfs(TreeNode* node){
        if(node==NULL){return;}
        swap(node->left,node->right);
        dfs(node->left);
        dfs(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};