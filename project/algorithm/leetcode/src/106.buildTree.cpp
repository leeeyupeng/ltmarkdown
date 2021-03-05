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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int i,int j,int length){
        if(length == 0){return NULL;}
        int nodeval = postorder[j+length-1];
        int inorderindex = map[nodeval];

        TreeNode* node = new TreeNode(nodeval);
        node->left = dfs(inorder,postorder,i,j,inorderindex-i);
        node->right = dfs(inorder,postorder,inorderindex + 1,j + inorderindex - i,length - (inorderindex-i) - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        
        for(int i = 0; i < n; i ++){
            map[inorder[i]] = i;
        }

        return dfs(inorder,postorder,0,0,n);
    }
};