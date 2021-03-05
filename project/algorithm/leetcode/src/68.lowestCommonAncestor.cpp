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
private:
    TreeNode* lowestCommons;
    pair<bool,bool> dfs(TreeNode* node,TreeNode* p, TreeNode* q){
        if(lowestCommons !=NULL){return {false,false}; }
        if(node==NULL){return {false,false};}
        pair<bool,bool> left = dfs(node->left,p,q);
        pair<bool,bool> right = dfs(node->right,p,q);
        pair<bool,bool> ans = {left.first||right.first||node==p,left.second||right.second||node==q};
        if(lowestCommons ==NULL && ans.first && ans.second){
            lowestCommons = node;
        }
        return ans;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          lowestCommons = NULL;
          dfs(root,p,q);
          return lowestCommons;
    }
};