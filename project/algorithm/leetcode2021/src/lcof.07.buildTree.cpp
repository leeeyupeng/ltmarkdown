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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int pi,int ii,int n){
        if(n==0){return NULL;}
        else if(n==1){
            return new TreeNode(preorder[pi]);
        }
        int index = 0;
        while(index<n){
            if(preorder[pi] == inorder[ii + index]){break;}
            index++;
        }
        TreeNode* node = new TreeNode(preorder[pi]);
        node->left = _buildTree(preorder,inorder,pi+1,ii,index);
        node->right = _buildTree(preorder,inorder,pi+index + 1,ii+index + 1,n - index - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return _buildTree(preorder,inorder,0,0,n);
    }
};