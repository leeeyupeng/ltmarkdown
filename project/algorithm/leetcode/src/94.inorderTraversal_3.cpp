#include"leetcode.h"
#include"leetcodenode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode2 {
 *     int val;
 *     TreeNode2 *left;
 *     TreeNode2 *right;
 *     TreeNode2(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    enum eFlag{
        LINK,
        CLUE,
    };
    struct TreeNode2{
        int val;
        TreeNode2* left;
        TreeNode2* right;
        eFlag lFlag;
        eFlag rFlag;
        TreeNode2(int _val):val(_val),left(NULL),right(NULL),lFlag(eFlag::LINK),rFlag(eFlag::LINK){}
    };

    //二叉树的中序遍历
    void _inorder(TreeNode2* node,vector<int>&ans){
        if(node==NULL){return;}
        _inorder(node->left,ans);
        ans.push_back(node->val);
        _inorder(node->right,ans);
    }
    vector<int> _inorderTraversal(TreeNode2* node){
        vector<int> ans;
        _inorder(node,ans);
        return ans;
    }
    //二叉树的中序线索化
    void _inorderCreateBTB(TreeNode2* node,TreeNode2* &pre){
        if(node==NULL){return;}    
        if(node->left==NULL){
            node->left=pre;
            node->lFlag = eFlag::CLUE;
        }
        else{
            _inorderCreateBTB(node->left,pre);
        }
        if(pre!=NULL && pre->right==NULL){
            pre->right = node;
            pre->rFlag = eFlag::CLUE;
        }
        pre = node;
        _inorderCreateBTB(node->right,pre);

    }
    void inorderCreateBTB(TreeNode2* node){
        TreeNode2* pre = NULL;
        _inorderCreateBTB(node,pre);
    }
    //遍历中序线索二叉树
    vector<int> inorderTraversalBTB(TreeNode2* node){
        vector<int> ans;
        if(node==NULL){return ans;}    
        TreeNode2* curNode = node;
        while(curNode!=NULL){
            while(curNode->lFlag == eFlag::LINK){curNode = curNode->left;}
            ans.push_back(curNode->val);
            while(curNode->rFlag == eFlag::CLUE){curNode = curNode->right;ans.push_back(curNode->val);}
            curNode=curNode->right;
        }
        return ans;
    }
    TreeNode2* convert(TreeNode* node){
        if(node==NULL){return NULL;}
        TreeNode2* node2 = new TreeNode2(node->val);
        node2->left = convert(node->left);
        //if(node2->left==NULL){node2->lFlag = eFlag::CLUE;}
        node2->right = convert(node->right);
        //if(node2->right==NULL){node2->rFlag = eFlag::CLUE;}
        return node2;
    }
public:
    vector<int> inorderTraversal(TreeNode*  root) {
        TreeNode2* root2 = convert(root);
        inorderCreateBTB(root2);
        vector<int> ans = inorderTraversalBTB(root2);
        return ans;
    }
};