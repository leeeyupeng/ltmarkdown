#include "leetcode.h"
 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> *q1 = new queue<TreeNode*>(),*q2= new queue<TreeNode*>();
        q1->push(root);
        double levelsums;
        int levelnums;
        TreeNode* node;
        while(!q1->empty()){
            levelnums = 0;
            levelsums = 0.0f;
            while(!q1->empty()){
                node = q1->front();
                q1->pop();
                if(node!=NULL){
                    levelnums++;
                    levelsums+=node->val;
                    q2->push(node->left);
                    q2->push(node->right);
                }
            }
            if(levelnums != 0){
                ans.push_back(levelsums / levelnums);
                swap(q1,q2);
            }else{
                swap(q1,q2);
            }
        }
        return ans;
    }
};