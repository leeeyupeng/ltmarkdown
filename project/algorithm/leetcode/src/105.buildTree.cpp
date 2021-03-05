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
    int n;
    unordered_map<int,int> map;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int i,int j,int length){
        if(length == 0){return NULL;}
        int nodeval = preorder[i];
        int inorderindex = map[nodeval];

        TreeNode* node = new TreeNode(nodeval);
        node->left = dfs(preorder,inorder,i+1,j,inorderindex-j);
        node->right = dfs(preorder,inorder,i + (inorderindex-j) + 1,inorderindex+1,length - (inorderindex-j) - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        
        for(int i = 0; i < n; i ++){
            map[inorder[i]] = i;
        }

        return dfs(preorder,inorder,0,0,n);
    }
};