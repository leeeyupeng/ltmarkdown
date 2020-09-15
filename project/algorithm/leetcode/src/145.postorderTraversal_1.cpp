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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        stack<TreeNode*> s2;
        s.push(root);
        TreeNode *node;
        while(!s.empty()){
            node = s.top();
                     
            if(node==NULL){s.pop();}
            else if(!s2.empty() && s2.top() == node){
                ans.push_back(node->val);
                s.pop();
                s2.pop();
            }else{
                s2.push(node);
                s.push(node->right);
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
//     vector<int> ans = s.postorderTraversal(root);

//     return 0;
// }