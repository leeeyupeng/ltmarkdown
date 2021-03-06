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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *node;
        while(!s.empty()){
            node = s.top();
            s.pop();
            if(node==NULL){continue;}
            ans.push_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }
        return ans;
    }
};

// int main(){
//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);

//     Solution s;
//     vector<int> ans = s.preorderTraversal(root);

//     return 0;
// }