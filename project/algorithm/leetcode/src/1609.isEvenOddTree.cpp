#include"leetcode.h"
#include"leetcodenode.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr){return true;}
        queue<TreeNode*> q;
        q.push(root);
        bool odd = true;
        int levelcount = 0;
        int nowvalue = 0;
        TreeNode* node;
        while(!q.empty()){
            levelcount = q.size();
            if(odd){nowvalue = 0;}
            else{nowvalue = 1000000+1;}
            while(levelcount > 0){
                levelcount --;
                node = q.front();
                q.pop();
                if(odd){
                    if((node->val&0x1) == 0x0){return false;}
                    if(node->val <= nowvalue){
                        return false;
                    }
                }
                else{
                    if((node->val&0x1) == 0x1){return false;}
                    if(node->val >= nowvalue){
                        return false;
                    }
                }
                nowvalue = node->val;
                if(node->left!=nullptr){q.push(node->left);}
                if(node->right!=nullptr){q.push(node->right);}
            }

            odd=!odd;
        }
        return true;
    }
};