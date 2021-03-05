#include"leetcode.h"
#include"leetcodenode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode * dfs(TreeNode *node1,TreeNode *node2){
        if(node1==NULL && node2==NULL){return NULL;}
        TreeNode * node;
        if(node1!=NULL && node2!=NULL){
            node = node1;
            node->val += node2->val;
            node->left = dfs(node1->left,node2->left);
            node->right = dfs(node1->right,node2->right);
        }
        else if(node1!=NULL){
            node = node1;
        }
        else if(node2!=NULL){
            node = node2;
        }
        return node;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1,t2);
    }
};