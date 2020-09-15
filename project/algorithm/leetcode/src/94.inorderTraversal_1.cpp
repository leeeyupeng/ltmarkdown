#include "leetcode.h"

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *node;
        while(!s.empty()){
            node = s.top();
            s.pop();
            if(node==NULL){continue;}
            if(!s.empty() &&  node->right == s.top()){
                ans.push_back(node->val);
            }else{
                s.push(node->right);
                s.push(node);
                s.push(node->left);
            }
        }
        return ans;
    }
};

// int main(){
//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);

//     Solution s;
//     vector<int> ans = s.inorderTraversal(root);

//     return 0;
// }