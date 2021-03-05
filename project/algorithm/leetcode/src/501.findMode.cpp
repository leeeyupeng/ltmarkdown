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
    int maxnums = 0;
    int dfs_nums(TreeNode *node,int parentvalue){
        if(node==NULL){return 0;}
        int nums=1;
        nums+=dfs_nums(node->left,node->val);
        nums+=dfs_nums(node->right,node->val);
        if(node->val == parentvalue){
            return nums;
        }else{
            maxnums = max(maxnums,nums);
            return 0;
        }
    }
    vector<int> ans;
    int dfs_max(TreeNode *node,int parentvalue){
        if(node==NULL){return 0;}
        int nums=1;
        nums+=dfs_max(node->left,node->val);
        nums+=dfs_max(node->right,node->val);
        if(node->val == parentvalue){
            return nums;
        }else{
            if(nums == maxnums){
                ans.push_back(node->val);
            }
            return 0;
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(root==NULL){return ans;}
        int nums = dfs_nums(root,0);
        maxnums = max(maxnums,nums);
        nums = dfs_max(root,0);
        if(maxnums!= 0 && nums == maxnums){
            ans.push_back(0);
        }
        return ans;
    }
};