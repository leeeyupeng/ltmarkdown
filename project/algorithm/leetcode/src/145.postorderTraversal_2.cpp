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
        stack<pair<TreeNode*,bool>> s;
        s.push({root,false});
        TreeNode *node;
        while(!s.empty()){
            node = s.top().first;   
            if(node==NULL){s.pop();}
            else if(s.top().second == true){
                ans.push_back(node->val);
                s.pop();
            }else{
                s.top().second = true;
                s.push({node->right,false});
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
//     vector<int> ans = s.postorderTraversal(root);

//     return 0;
// }