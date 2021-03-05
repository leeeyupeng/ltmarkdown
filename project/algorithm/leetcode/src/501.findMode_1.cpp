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
    vector<int> ans;
    vector<int> vsort;
    void dfs(TreeNode *node){
        if(node==NULL){return;}
        dfs(node->left);
        vsort.push_back(node->val);
        dfs(node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(root == NULL){return ans;}
        dfs(root);
        int n = vsort.size();
        int nums = 1;
        for(int i = 1; i < n; i ++){
            if(vsort[i]!=vsort[i-1]){maxnums=max(maxnums,nums);nums = 1;}
            else{nums++;}
        }
        maxnums=max(maxnums,nums);
        nums = 1;
        for(int i = 1; i < n; i ++){
            if(vsort[i]!=vsort[i-1]){if(nums == maxnums){ans.push_back(vsort[i-1]);};nums = 1;}
            else{nums++;}
        }
        if(nums == maxnums){ans.push_back(vsort[n-1]);}
        return ans;
    }
};