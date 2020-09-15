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
        stack<pair<TreeNode*,bool>> s;
        s.push({root,false});
        TreeNode *node;
        pair<TreeNode*,bool>  p;
        while(!s.empty()){
            p = s.top();
            s.pop();
            node = p.first; 
            if(node==NULL){continue;}
            if(p.second == true){
                ans.push_back(node->val);
            }else{
                s.push({node->right,false});
                s.push({node,true});
                s.push({node->left,false});
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